#ifndef __COEX_INTERFACES_ITHREADTASK_H__
#define __COEX_INTERFACES_ITHREADTASK_H__

#include "itypeoperationsystem.h"
#include "iconfig.h"
#include <QString>
#include <QStringList>

namespace coex
{
	// interface of task
	class ITask
	{
		public:
			// information about task
			virtual QString help() = 0;
			virtual QString name() = 0;
			virtual QString author() = 0;
			virtual QString description() = 0;
			virtual QString license() = 0;
			virtual QString licenseFull() = 0;

			virtual bool isSupportOS(const coex::ITypeOperationSystem *os) = 0;
			virtual bool init(const coex::IConfig *config) = 0;
			virtual bool execute() = 0;
	};
}

#endif // __COEX_INTERFACES_ITHREADTASK_H__
