include(version.pri)

TEMPLATE = app
TARGET = coex-searchgitrepo-ui
DESTDIR = bin/
OBJECTS_DIR = tmp/
QT += gui core widgets xml printsupport

ICON = images/logo_48x48.icns

INCLUDEPATH += src/coex/v0.2.2/interfaces/

RESOURCES = images.qrc

SOURCES += \
	src/app_ui.cpp \
	src/task.cpp \
	src/coex/v0.2.2/helpers/config.cpp \
	src/coex/v0.2.2/helpers/typeos.cpp \
	src/ui/window.cpp \
	src/ui/tablemodel_gitrepos.cpp

HEADERS += \
	src/coex/coex.h \
	src/coex/v0.2.2/helpers/config.h \
	src/coex/v0.2.2/helpers/typeos.h \
	src/ui/window.h \
	src/task.h \
	src/ui/tablemodel_gitrepos.h
