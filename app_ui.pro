include(version.pri)

TEMPLATE = app
TARGET = forensictool-git-ui
DESTDIR = bin/
OBJECTS_DIR = tmp/
QT += gui core widgets xml printsupport

ICON = images/logo_48x48.icns

INCLUDEPATH += src/forensictool-core/v0.3.1/interfaces/

RESOURCES = images.qrc

SOURCES += \
	src/app_ui.cpp \
	src/task.cpp \
	src/forensictool-core/v0.3.1/helpers/config.cpp \
	src/forensictool-core/v0.3.1/helpers/typeos.cpp \
	src/ui/window.cpp \
	src/ui/tablemodel_gitrepos.cpp

HEADERS += \
	src/forensictool-core/v0.3.1/helpers/config.h \
	src/forensictool-core/v0.3.1/helpers/typeos.h \
	src/ui/window.h \
	src/task.h \
	src/ui/tablemodel_gitrepos.h
