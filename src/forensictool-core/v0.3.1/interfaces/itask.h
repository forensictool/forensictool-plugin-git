#ifndef __FORENSICTOOL_INTERFACES_ITASK_H__
#define __FORENSICTOOL_INTERFACES_ITASK_H__

#include "itypeoperationsystem.h"
#include "iconfig.h"
#include <QString>
#include <QStringList>

namespace forensictool
{
	// interface of task
	class ITask
	{
		public:
			// information about task
			virtual QString help() = 0;
			virtual QString name() = 0;
			virtual QStringList authors() = 0;
			virtual QString description() = 0;
			virtual QString license() = 0;
			virtual QString licenseFull() = 0;

			virtual bool isSupportOS(const forensictool::ITypeOperationSystem *os) = 0;
			virtual bool init(const forensictool::IConfig *config) = 0;
			virtual bool execute() = 0;
	};
}

#endif // __FORENSICTOOL_INTERFACES_ITASK_H__
