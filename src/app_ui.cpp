#include <iostream>
#include <QApplication>
#include <QDesktopWidget>
#include "task.h"
#include "forensictool.h"
#include "forensictool-core/v0.3.1/helpers/config.h"
#include "forensictool-core/v0.3.1/helpers/typeos.h"
#include "ui/window.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	GitSearchRepoWindow w;
	
	// center of desctop
	QDesktopWidget wid;
	int screenWidth = wid.screen()->width();
	int screenHeight = wid.screen()->height();
	w.setGeometry((screenWidth/2)-(w.width()/2),(screenHeight/2)-(w.height()/2),w.width(),w.height());
	
	w.show();
	return app.exec();
};
