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
		
/*	QStringList args;
	for(int i = 0; i < argc; i++){
		args << QString(argv[i]);
	}
	
	if(!args.contains("--input-folder") || !args.contains("--output-folder")){
		printHelp(args);
		return -1;
	}

	if(args.contains("--help")){
		printHelp(args);
		return 0;
	}
	
	QString inputFolder = "";
	if(args.contains("--input-folder") && args.indexOf("--input-folder") + 1 > args.size()){
		std::cout << "\nERROR: Could not found parameter for '--input-folder'\n";
		printHelp(args);
		return -2;
	}else{
		inputFolder = args[args.indexOf("--input-folder") + 1];
	}
	
	QString outputFolder = "";
	if(args.contains("--output-folder") && args.indexOf("--output-folder") + 1 > args.size()){
		std::cout << "\nERROR: Could not found parameter for '--output-folder'\n";
		printHelp(args);
		return -3;
	}else{
		outputFolder = args[args.indexOf("--output-folder") + 1];
	}
	
	args << "--debug"; // always debug on
	
	coex::IConfig *pConfig = (coex::IConfig *)(new Config());
	
	pConfig->setInputFolder(inputFolder);
	pConfig->setOutputFolder(outputFolder);
	pConfig->setTypeOS((coex::ITypeOperationSystem *)(new TypeOS()));
	
	coex::ITask* pTask = (coex::ITask*)(new TaskSearchGitRepository());
	
	pTask->setOption(args);
	std::cout << "\n\n";
	pTask->execute(pConfig);
	return 0;*/
};
