// ***********************************************************************************************
// *                                                                                             *
// * createMenu.cpp - creates application menus                                                  *
// *                                                                                             *
// * Dr. Rainer Sieger - 2008-05-18                                                              *
// *                                                                                             *
// ***********************************************************************************************

#include "Application.h"

// **********************************************************************************************
// **********************************************************************************************
// **********************************************************************************************

/*! @brief Erstellen der Menue-Aktionen. */

void MainWindow::createActions()
{
// File menu
    newWindowAction = new QAction(tr("&New window"), this);
    newWindowAction->setShortcut(tr("Ctrl+N"));
    connect(newWindowAction, SIGNAL(triggered()), this, SLOT(newWindow()));

    openFileAction = new QAction(tr("&Open..."), this);
    openFileAction->setShortcut(tr("Ctrl+O"));
    connect(openFileAction, SIGNAL(triggered()), this, SLOT(chooseFiles()));

    openFolderAction = new QAction(tr("Select &Folder..."), this);
    openFolderAction->setShortcut(tr("Ctrl+F"));
    connect(openFolderAction, SIGNAL(triggered()), this, SLOT(chooseFolder()));

    saveAction = new QAction(tr("&Save"), this);
    saveAction->setShortcut(tr("Ctrl+S"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));

    saveAsAction = new QAction(tr("Save &As..."), this);
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveFileAs()));

    hideWindowAction = new QAction(tr("&Close window"), this);
    hideWindowAction->setShortcut(tr("Ctrl+W"));
    connect(hideWindowAction, SIGNAL(triggered()), this, SLOT(hideWindow()));

    exitAction = new QAction(tr("&Quit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    setGlobalOptionsDialogAction = new QAction(tr("Settings..."), this);
    setGlobalOptionsDialogAction->setShortcut(tr("Ctrl+,"));
    connect(setGlobalOptionsDialogAction, SIGNAL(triggered()), this, SLOT(doSetGlobalOptionsDialog()));

    runBenthosScriptAction = new QAction(tr("&Run Benthos script"), this);
    runBenthosScriptAction->setShortcut(tr("Ctrl+B"));
    connect(runBenthosScriptAction, SIGNAL(triggered()), this, SLOT(doBuildBenthosScript()));

    runCoresScriptAction = new QAction(tr("&Run Cores script"), this);
    runCoresScriptAction->setShortcut(tr("Ctrl+C"));
    connect(runCoresScriptAction, SIGNAL(triggered()), this, SLOT(doBuildCoresScript()));

    setLastDownloadDateDialogAction = new QAction(tr("Set last Jubany download &date..."), this);
    setLastDownloadDateDialogAction->setShortcut(tr("Ctrl+D"));
    connect(setLastDownloadDateDialogAction, SIGNAL(triggered()), this, SLOT(doSetLastDownloadDateDialog()));

    getDatesAction = new QAction(tr("&Get new Jubany dates"), this);
    getDatesAction->setShortcut(tr("Ctrl+G"));
    connect(getDatesAction, SIGNAL(triggered()), this, SLOT(doGetDates()));

    runScriptAction = new QAction(tr("&Run Jubany script"), this);
    runScriptAction->setShortcut(tr("Ctrl+R"));
    connect(runScriptAction, SIGNAL(triggered()), this, SLOT(doCreateJubanyThumbnails()));

    // Help menu
    aboutAction = new QAction(tr("&About ") + getApplicationName(), this);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    showHelpAction = new QAction(getApplicationName() + tr(" &Help"), this);
    showHelpAction->setShortcut(tr("F1"));
    connect(showHelpAction, SIGNAL(triggered()), this, SLOT(displayHelp()));

#if defined(Q_OS_WIN)
    newWindowAction->setStatusTip(tr("Create a new file"));
    runScriptAction->setStatusTip(tr("Run the upload script"));
    openFolderAction->setStatusTip(tr("Choose an existing folder"));
    saveAction->setStatusTip(tr("Save the document to disk"));
    saveAsAction->setStatusTip(tr("Save the document under a new name"));
    exitAction->setStatusTip(tr("Exit the application"));
    setGlobalOptionsDialogAction->setStatusTip(tr("Set global options"));
    aboutAction->setStatusTip(tr("Show the application's About box"));
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    showHelpAction->setStatusTip(tr("Show the application's help"));
#endif

}

// **********************************************************************************************
// **********************************************************************************************
// **********************************************************************************************

/*! @brief Verbindet Menues mit Aktionen. */

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu( tr( "&File" ) );
    fileMenu->addAction( openFileAction );
    fileMenu->addAction( openFolderAction );
    fileMenu->addSeparator();

#if defined(Q_OS_LINUX)
    ;
#endif

#if defined(Q_OS_MAC)
    fileMenu->addAction( newWindowAction );
    newWindowAction->setEnabled( false );
    fileMenu->addAction( hideWindowAction );
#endif

#if defined(Q_OS_WIN)
    fileMenu->addAction( hideWindowAction );
#endif

    fileMenu->addSeparator();
    fileMenu->addAction( setGlobalOptionsDialogAction );

#if defined(Q_OS_LINUX)
    fileMenu->addSeparator();
    fileMenu->addAction( exitAction );
#endif

#if defined(Q_OS_WIN)
    fileMenu->addSeparator();
    fileMenu->addAction( exitAction );
#endif

// **********************************************************************************************

    scriptMenu = menuBar()->addMenu( tr( "&Script" ) );
    scriptMenu->addAction( runBenthosScriptAction );
    scriptMenu->addAction( runCoresScriptAction );
/*
    scriptMenu->addSeparator();
    scriptMenu->addAction( setLastDownloadDateDialogAction );
    scriptMenu->addAction( getDatesAction );
*/

    scriptMenu->addAction( runScriptAction );

    helpMenu = menuBar()->addMenu( tr( "&Help" ) );
    helpMenu->addAction( aboutAction );
    helpMenu->addAction( aboutQtAction );
    helpMenu->addSeparator();
    helpMenu->addAction( showHelpAction );
}