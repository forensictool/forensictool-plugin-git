include(version.pri)

TEMPLATE = app
TARGET = coex-searchgitrepo
DESTDIR = bin/
OBJECTS_DIR = tmp/
QT -= gui

INCLUDEPATH += src/coex/v0.2.2/interfaces/

SOURCES += \
	src/app.cpp \
	src/task.cpp \
	src/coex/v0.2.2/helpers/config.cpp \
	src/coex/v0.2.2/helpers/typeos.cpp \

HEADERS += \
	src/coex/v0.2.2/helpers/config.h \
	src/coex/v0.2.2/helpers/typeos.h \
	src/task.h


