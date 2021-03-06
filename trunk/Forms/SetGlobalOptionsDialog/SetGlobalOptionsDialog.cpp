#include <QtWidgets>

#include "Application.h"
#include "SetGlobalOptionsDialog.h"

// ****************************************************************************
// ****************************************************************************
// ****************************************************************************

void MainWindow::doSetGlobalOptionsDialog()
{
    SetGlobalOptionsDialog dialog( this );

    dialog.WorkingDirectory_lineEdit->setText( gs_WorkingDirectory );

    dialog.User_hssrv2_lineEdit->setText( gs_User_hssrv2 );
    dialog.Password_hssrv2_lineEdit->setText( gs_Password_hssrv2 );

    dialog.User_pangaea_lineEdit->setText( gs_User_pangaea );
    dialog.Password_pangaea_lineEdit->setText( gs_Password_pangaea );

    dialog.OK_pushButton->setWhatsThis( "Close dialog" );
    dialog.Cancel_pushButton->setWhatsThis( "Cancel dialog" );

    dialog.move( posDialog );
    dialog.resize( dialog.sizeHint() );
    dialog.show();

// ******************************************************************************************************

    switch ( dialog.exec() )
    {
    case QDialog::Accepted:
        gs_WorkingDirectory     = dialog.WorkingDirectory_lineEdit->text();

        gs_User_hssrv2          = dialog.User_hssrv2_lineEdit->text();
        gs_Password_hssrv2      = dialog.Password_hssrv2_lineEdit->text();

        gs_User_pangaea         = dialog.User_pangaea_lineEdit->text();
        gs_Password_pangaea     = dialog.Password_pangaea_lineEdit->text();

        break;

    case QDialog::Rejected:
        break;

    default:
        break;
    }

    posDialog = dialog.pos();
}

// ****************************************************************************
// ****************************************************************************
// ****************************************************************************

SetGlobalOptionsDialog::SetGlobalOptionsDialog( QWidget *parent ) : QDialog( parent )
{
    setupUi( this );

    connect(OK_pushButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(Cancel_pushButton, SIGNAL(clicked()), this, SLOT(reject()));

    connect(browseWorkingDirectory_pushButton, SIGNAL(clicked()), this, SLOT( browseWorkingDirectoryDialog() ));
}

// ***********************************************************************************************************************
// ***********************************************************************************************************************
// ***********************************************************************************************************************

void SetGlobalOptionsDialog::browseWorkingDirectoryDialog()
{
    QString Path		= WorkingDirectory_lineEdit->text();
    QString startPath   = getPersonalDir();
    QString	resultPath  = "";

// ***********************************************************************************************************************

    startPath.replace( "://", ":/" );

    if ( Path.isEmpty() == false )
        startPath = Path;

    resultPath = QFileDialog::getExistingDirectory( this, tr( "Choose a folder" ), startPath, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks );

    if ( resultPath.isEmpty() == true )
        resultPath = startPath;

    WorkingDirectory_lineEdit->setText( QDir::toNativeSeparators( resultPath ) );

    WorkingDirectory_lineEdit->setFocus();
}

// ***********************************************************************************************************************
// ***********************************************************************************************************************
// ***********************************************************************************************************************

QString SetGlobalOptionsDialog::getPersonalDir()
{
    QString s_PersonalDir	= QDir::homePath();
    QString s_HomeDir		= QDir::homePath();

    #if defined(Q_OS_WIN)
        QSettings settings( "Microsoft", "Windows" );
        s_PersonalDir = settings.value( "/CurrentVersion/Explorer/Shell Folders/Personal" ).toString();
    #endif

    #if defined(Q_OS_MAC)
        s_PersonalDir = s_HomeDir;
    #endif

    return( QDir::toNativeSeparators( s_PersonalDir ) );
}

// ***********************************************************************************************************************
// ***********************************************************************************************************************
// ***********************************************************************************************************************

QString SetGlobalOptionsDialog::getProgramDir()
{
    QString     s_ProgramDir   = "";

    #if defined(Q_OS_WIN)
        int         i              = 0;
        QStringList sl_Environment = QProcess::systemEnvironment();
        while ( ( s_ProgramDir.isEmpty() == true ) && ( ++i < sl_Environment.count() ) )
            if ( sl_Environment.at( i ).startsWith( "PROGRAMFILES=", Qt::CaseInsensitive ) == true )
                s_ProgramDir = sl_Environment.at( i ).section( "=", 1, 1 );
    #endif

    #if defined(Q_OS_MAC)
        s_ProgramDir = QDir::homePath();
    #endif

    return( QDir::toNativeSeparators( s_ProgramDir ) );
}

