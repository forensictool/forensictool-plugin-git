include(version.pri)

TEMPLATE = app
TARGET = coex-searchgitrepo-ui
DESTDIR = bin/
OBJECTS_DIR = tmp/
QT += gui core widgets xml printsupport

RESOURCES = images.qrc

SOURCES += \
	src/app_ui.cpp \
	src/task.cpp \
	src/coex/config.cpp \
	src/coex/typeos.cpp \
	src/ui/window.cpp \

HEADERS += \
	src/coex/coex.h \
	src/coex/config.h \
	src/coex/typeos.h \
	src/ui/window.h \
	src/task.h
