# PanUploader - creats thumbnails form photographs and upload them to store.pangaea.de and hs.pangaea.de
# Rainer Sieger
# Alfred Wegener Institute, Bremerhaven, Germany
# last change: 2017-02-02

macx {
    # creating cache file
    cache()

    # Set SDK
    QMAKE_MAC_SDK = macosx10.13 # Xcode 9 - 2017-09-20

    # Only Intel binaries are accepted so force this
    CONFIG += x86_64

    # Minimum OS X version for submission is 10.7
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7

    # Icon
    ICON = ./Resources/icon/Application.icns

    # Replace default Info.plist
    QMAKE_INFO_PLIST = ./Resources/Info.plist

    QMAKE_CFLAGS += -gdwarf-2
    QMAKE_CXXFLAGS += -gdwarf-2
    QMAKE_CFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
    QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CXXFLAGS_RELEASE_WITH_DEBUGINFO
    QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO
}

win32 {
    # Icon
    RC_FILE = ./Resources/Application.rc
}

linux-g++ {
}

TARGET = PanUploader
TEMPLATE = app

QT += widgets network

INCLUDEPATH += ./Headers

HEADERS = ./Headers/Application.h \
    ./Headers/Globals.h \
    ./Headers/simplecrypt.h \
    ./Forms/AboutDialog/AboutDialog.h \
    ./Forms/SetGlobalOptionsDialog/SetGlobalOptionsDialog.h \
    ./Forms/SetThumbnailOptionsDialog/SetThumbnailOptionsDialog.h \
    ./Forms/SetTurnImagesOptionsDialog/SetTurnImagesOptionsDialog.h

SOURCES = ./Sources/ApplicationInit.cpp \
    ./Sources/ApplicationMainWindow.cpp \
    ./Sources/ApplicationErrors.cpp \
    ./Sources/ApplicationPreferences.cpp \
    ./Sources/ApplicationCreateMenu.cpp \
    ./Sources/createDummyFiles.cpp \
    ./Sources/turnImages.cpp \
    ./Sources/uploadImages.cpp \
    ./Sources/uploadImagesJubany.cpp \
    ./Sources/simplecrypt.cpp \
    ./Forms/AboutDialog/AboutDialog.cpp \
    ./Forms/SetGlobalOptionsDialog/SetGlobalOptionsDialog.cpp \
    ./Forms/SetThumbnailOptionsDialog/SetThumbnailOptionsDialog.cpp \
    ./Forms/SetTurnImagesOptionsDialog/SetTurnImagesOptionsDialog.cpp

FORMS = ./Forms/AboutDialog/aboutdialog.ui \
    ./Forms/SetGlobalOptionsDialog/setglobaloptionsdialog.ui \
    ./Forms/SetThumbnailOptionsDialog/setthumbnailoptionsdialog.ui \
    ./Forms/SetTurnImagesOptionsDialog/setturnimagesoptionsdialog.ui
