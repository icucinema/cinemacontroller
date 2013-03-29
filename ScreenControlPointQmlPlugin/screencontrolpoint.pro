TEMPLATE = lib
TARGET = ScreenControlPoint
QT += qml quick
CONFIG += qt plugin

TARGET = $$qtLibraryTarget($$TARGET)
uri = uk.co.icucinema.ScreenControlPoint

# Input
SOURCES += \
    screencontrolpoint_plugin.cpp \
    screencontrolpoint.cpp

HEADERS += \
    screencontrolpoint_plugin.h \
    screencontrolpoint.h

OTHER_FILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_IMPORTS]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}


win32:CONFIG(release, debug|release): LIBS += -L/opt/hupnp/lib/release/ -lHUpnp
else:win32:CONFIG(debug, debug|release): LIBS += -L/opt/hupnp/lib/debug/ -lHUpnp
else:unix: LIBS += -L/opt/hupnp/lib/ -lHUpnp

INCLUDEPATH += /opt/hupnp/include
DEPENDPATH += /opt/hupnp/include

unix|win32: LIBS += -L/opt/hupnp/lib/ -lQtSolutions_SOAP-2.7
