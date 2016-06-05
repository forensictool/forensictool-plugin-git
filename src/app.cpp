#include <iostream>
#include "task.h"
#include "coex.h"

void printHelp(QStringList &args){
	coex::ITask* pTask = (coex::ITask*)(new TaskSearchGitRepository());
	std::cout << "\n" << pTask->description().toStdString() << "\n\n";
	std::cout << "  Usage: " << args[0].toStdString() << " [OPTIONS] \n\n";
	std::cout << "  OPTIONS:\n\n";
	std::cout << "    --input-folder <fullpath>       - required parameter\n";
	std::cout << "    --output-folder <fullpath>      - required parameter\n";
	std::cout << "    --help                          - this help\n";
	std::cout << "\n";
	std::cout << "  Version: " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_BUILD << "\n";
	std::cout << "  Author: " << pTask->author().toStdString() << "\n\n";
	// std::cout << "  LICENSE: " << pTask->license().toStdString() << "\n";
}

class Config : public coex::IConfig {
	public:
		virtual QString inputFolder() const { return m_sInputFolder; };
		virtual QString outputFolder() const { return m_sOutputFolder; };
		virtual const coex::ITypeOperationSystem* typeOS() const { return m_pTypeOS; };
		
		virtual void setInputFolder(QString path) { m_sInputFolder = path; };
		virtual void setOutputFolder(QString path) { m_sOutputFolder = path; };
		virtual void setTypeOS(coex::ITypeOperationSystem* pTypeOS) { m_pTypeOS = pTypeOS; };
		
		virtual bool isUnknownOS() { return false; };
		virtual bool isWindows() { return true; };
		virtual bool isLinux() { return true; };

		virtual bool getArgumentsValues(int, char**, QString) { return true; };
		virtual bool isDebugEnable() const { return true; };
	private:
		coex::ITypeOperationSystem* m_pTypeOS;
		QString m_sInputFolder;
		QString m_sOutputFolder;
		
};

class TypeOS : public coex::ITypeOperationSystem {
	public:
		virtual QString platform() const { return "SomeOS"; };
		virtual void setPlatform(QString) {};

		virtual QString version() const { return "0"; };
		virtual void setVersion(QString) {};

		virtual QString toString() const { return "SomeOS0"; };
};

int main(int argc, char* argv[])
{
	QStringList args;
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
	return 0;
};
