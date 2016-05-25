#.pro file
#Application version
VERSION_MAJOR = 0
VERSION_MINOR = 0
VERSION_BUILD = 1

DEFINES += "VERSION_MAJOR=$$VERSION_MAJOR"\
       "VERSION_MINOR=$$VERSION_MINOR"\
       "VERSION_BUILD=$$VERSION_BUILD"

VERSION = $${VERSION_MAJOR}.$${VERSION_MINOR}.$${VERSION_BUILD}


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


