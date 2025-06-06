QT += quick
QT += sql

#QT += statemachine
#QT += core5compat


CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        basscontroller.cpp \
        controller.cpp \
        filevalidator.cpp \
        main.cpp \
        radio.cpp \
        radiomodel.cpp \
        testobject.cpp

RESOURCES += qml.qrc \
    app_icons.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    bassPlay.h \
    basscontroller.h \
    controller.h \
    filevalidator.h \
    radio.h \
    radiomodel.h \
    testobject.h




win32: LIBS += -L$$PWD/bass/ -lbass

INCLUDEPATH += $$PWD/bass
DEPENDPATH += $$PWD/bass
