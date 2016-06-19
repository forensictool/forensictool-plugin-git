#ifndef __TASK_SEARCH_GIT_REPOSITORY_H__
#define __TASK_SEARCH_GIT_REPOSITORY_H__

#include "coex.h"

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

class TaskSearchGitRepository : coex::ITask
{
	public:
		TaskSearchGitRepository();
		virtual QString help();
		virtual QString name();
		virtual QString author();
		virtual QString description();
		virtual QString license();
		virtual QString licenseFull();

		virtual bool isSupportOS(const coex::ITypeOperationSystem *os);
		virtual bool init(const coex::IConfig *pConfig);
		virtual bool execute();
        
	private:
		void writeStartAdd();
		void writeEndAdd();
		void writeField(QString sName,QString sValue);

        void processGitFolder(QString medianame);
        
		bool m_bDebug;
		const coex::IConfig *m_pConfig;
		QXmlStreamWriter *m_pWriter;
};

extern "C"
{
	coex::ITask* createTask();
}

#endif // __TASK_SEARCH_GIT_REPOSITORY_H__
