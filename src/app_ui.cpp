#include <iostream>
#include <QApplication>
#include <QDesktopWidget>
#include "task.h"
#include "coex/coex.h"
#include "coex/config.h"
#include "coex/typeos.h"
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
