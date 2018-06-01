#-------------------------------------------------
#
# Project created by QtCreator 2018-04-03T13:59:09
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TakePhotos
TEMPLATE = app


SOURCES += main.cpp\
        TakePhotos.cpp \
        checkstatus.cpp \
        idcardreader.cpp \
        putchinesetext.cpp \
        serversettings.cpp \
        submitdata.cpp \
        textsettings.cpp \
        idcardmessage.cpp \
        servicetimelinetable.cpp \
        historyviewer.cpp

HEADERS  += TakePhotos.h \
        checkstatus.h \
        idcardreader.h \
        putchinesetext.h \
        serversettings.h \
        submitdata.h \
        textsettings.h \
        idcardmessage.h \
        servicetimelinetable.h \
        historyviewer.h

FORMS    += TakePhotos.ui \
            textsettings.ui \
            serversettings.ui \
            servicetimelinetable.ui \
            historyviewer.ui

INCLUDEPATH += . \
    ../Curl/include \
    ../OpenCV/include \

LIBS +=-L../OpenCV/x86/mingw/lib \
    -L../Curl\lib \
    -lopengl32 \
    -lglu32 \
    -lopencv_core340 \
    -lopencv_highgui340 \
    -lopencv_videoio340 \
    -llibcurl_imp \
    -lws2_32 \
    -lwldap32 \
    -lopencv_imgproc340 \
    -lgdi32
VERSION = 1.5.1.0
TRANSLATIONS =zh_CN.ts
RC_ICONS = TakePhotos.ico
QMAKE_TARGET_COMPANY = "NNSI"
QMAKE_TARGET_DESCRIPTION = "Service TimeLine"
RC_LANG = 0x0004
QMAKE_TARGET_PRODUCT = "Service TimeLine"
QMAKE_TARGET_COPYRIGHT = "Copyright 2018 Li Shuhua All rights reserved."
win32:RC_FILE += TakePhotos_resource.rc
