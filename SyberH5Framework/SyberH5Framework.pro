include(../syberos.pri)
QT += gui qml quick widgets

TEMPLATE = app

TARGET = SyberH5Framework

CONFIG += link_pkgconfig
PKGCONFIG += syberos-qt-system
RESOURCES += res.qrc

PKGCONFIG += syberos-application syberos-application-cache

QML_FILES = qml/*.qml

OTHER_FILES += $$QML_FILES *.qm \
    qml/logic.js


# The .cpp file which was generated for your project.
SOURCES += src/main.cpp \
           src/SyberH5Framework_Workspace.cpp \
    src/syberh5helpper.cpp \
    src/biginteger.cpp \
    src/rsa.cpp \
    src/encryptdecrypt.cpp \
    src/taesclass.cpp \
    src/aes.cpp \
    src/base64.cpp

HEADERS += src/SyberH5Framework_Workspace.h \
    src/syberh5helpper.h \
    src/biginteger.h \
    src/rsa.h \
    src/encryptdecrypt.h \
    src/taesclass.h \
    src/aes.h \
    src/base64.h

# Installation path
target.path = $$INSTALL_DIR/bin

qm.files = *.qm
qm.path = $$INSTALL_DIR/qm

web.files = www
web.path = $$INSTALL_DIR

INSTALLS += target qm web

DISTFILES +=

