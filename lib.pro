include(version.pri)

TEMPLATE = lib
TARGET = forensictool-plugin-git
DESTDIR = bin/
OBJECTS_DIR = tmp/
QT -= gui
CONFIG += dll

INCLUDEPATH += src/forensictool-core/v0.3.1/interfaces/

SOURCES += \
	src/lib.cpp \
	src/task.cpp \


HEADERS += \
	src/task.h


