#ifndef __COEX_H__
#define __COEX_H__

#include <QString>
#include <QVector>
#include <iostream>

#include <QObject>

namespace coex
{
	class ITypeOperationSystem {
		public:
			// platform: "Windows" or "Linux"
			virtual QString platform() const = 0;
			virtual void setPlatform(QString platform) = 0;
			
			// for platform "Windows" version can be "95" or "98" or "XP" or "Vista" or "7" or "8"
			virtual QString version() const = 0;
			virtual void setVersion(QString version) = 0;

			virtual QString toString() const = 0;
	};


	/* interface for
	 * config object 
	 * */
	class IConfig {
		public:
			virtual QString inputFolder() const = 0;
			virtual QString outputFolder() const = 0;
			virtual const coex::ITypeOperationSystem* typeOS() const = 0;
			
			virtual void setInputFolder(QString path) = 0;
			virtual void setOutputFolder(QString path) = 0;
			virtual void setTypeOS(coex::ITypeOperationSystem*) = 0;
			
			virtual bool isUnknownOS() = 0;
			virtual bool isWindows() = 0;
			virtual bool isLinux() = 0;

			virtual bool getArgumentsValues(int, char**, QString) = 0;
			virtual bool isDebugEnable() const = 0;
	};
	
	/* interface for
	 * detect operation system 
	 * must be TODO */
	class IDetectOperationSystem {
		public:
			virtual coex::ITypeOperationSystem* detect(QString path) = 0;
			virtual QString name() = 0;
			virtual QString author() = 0;
			virtual QVector<coex::ITypeOperationSystem *> getSupportsOS() = 0;
	};

	class ITask
	{
		public:
			virtual QString help() = 0;
			virtual QString name() = 0;
			virtual QString author() = 0;
			virtual QString description() = 0;

			virtual bool isSupportOS(const coex::ITypeOperationSystem *os) = 0;
			virtual void setOption(QStringList) = 0;
			virtual bool execute(const coex::IConfig *config) = 0;
	};
	
	class IThreadTask : public QObject
	{
		public:
			virtual ~IThreadTask(){};
			virtual QString help() = 0;
			virtual QString name() = 0;
			virtual QString author() = 0;
			virtual QString description() = 0;

			virtual bool isSupportOS(const coex::ITypeOperationSystem *os) = 0;
			virtual void setOption(QStringList) = 0;
			virtual void init(const coex::IConfig *config) = 0;

		public slots:
			virtual bool execute() = 0;
	};
}

Q_DECLARE_INTERFACE (coex::IThreadTask, "IThreadTask");

#endif //__COEX_H__
