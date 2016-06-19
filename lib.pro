include(version.pri)

TEMPLATE = lib
TARGET = coex-plugin-task-searchgitrepo
DESTDIR = bin/
OBJECTS_DIR = tmp/
QT -= gui
CONFIG += dll

INCLUDEPATH += src/coex/v0.2.2/interfaces/

SOURCES += \
	src/lib.cpp \
	src/task.cpp \


HEADERS += \
	src/coex.h \
	src/task.h


