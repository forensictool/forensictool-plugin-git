include(version.pri)

TEMPLATE = app
TARGET = coex-searchgitrepo
DESTDIR = bin/
OBJECTS_DIR = tmp/
QT -= gui
CONFIG += dll
SOURCES += \
	src/app.cpp \
	src/task.cpp \


HEADERS += \
	src/coex.h \
	src/task.h


