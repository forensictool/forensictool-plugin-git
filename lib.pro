include(version.pri)

TEMPLATE = lib
TARGET = coex-plugin-task-searchgitrepo
DESTDIR = bin/
OBJECTS_DIR = tmp/
QT -= gui
CONFIG += dll
SOURCES += \
	src/lib.cpp \
	src/task.cpp \


HEADERS += \
	src/coex.h \
	src/task.h


