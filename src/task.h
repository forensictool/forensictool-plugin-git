#ifndef __TASK_SEARCH_GIT_REPOSITORY_H__
#define __TASK_SEARCH_GIT_REPOSITORY_H__

#include "forensictool.h"

#include <QCryptographicHash>
#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QDirIterator>
#include <QDataStream>
#include <QFile>
#include <QFileInfo>
#include <QString>
#include <QStringList>
#include <QXmlStreamWriter>

class TaskSearchGitRepository : forensictool::ITask
{
	public:
		TaskSearchGitRepository();
		virtual QString help();
		virtual QString name();
		virtual QStringList authors();
		virtual QString description();
		virtual QString license();
		virtual QString licenseFull();

		virtual bool isSupportOS(const forensictool::ITypeOperationSystem *os);
		virtual bool init(const forensictool::IConfig *pConfig);
		virtual bool execute();
        
	private:
		void writeStartAdd();
		void writeEndAdd();
		void writeField(QString sName,QString sValue);

        void processGitFolder(QString medianame);
        
		bool m_bDebug;
		const forensictool::IConfig *m_pConfig;
		QXmlStreamWriter *m_pWriter;
};

extern "C"
{
	forensictool::ITask* createTask();
}

#endif // __TASK_SEARCH_GIT_REPOSITORY_H__
