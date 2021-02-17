QT   += core gui widgets sql widgets

greaterThan(QT_MAJOR_VERSION, 4):

CONFIG += c++17

SOURCES += \
    dbconnection.cpp \
    fileio.cpp \
    main.cpp \
    choosewindow.cpp

HEADERS += \
    choosewindow.h \
    dbconnection.h \
    fileio.h \
    genome.h

FORMS += \
    choosewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
