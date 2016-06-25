include(version.pri)

TEMPLATE = app
TARGET = forensictool-git
DESTDIR = bin/
OBJECTS_DIR = tmp/
QT -= gui

INCLUDEPATH += src/forensictool-core/v0.3.1/interfaces/

SOURCES += \
	src/app.cpp \
	src/task.cpp \
	src/forensictool-core/v0.3.1/helpers/config.cpp \
	src/forensictool-core/v0.3.1/helpers/typeos.cpp \

HEADERS += \
	src/forensictool-core/v0.3.1/helpers/config.h \
	src/forensictool-core/v0.3.1/helpers/typeos.h \
	src/task.h


