#ifndef __COEX_INTERFACES_IDETECTOROPERATIONSYSTEM_H__
#define __COEX_INTERFACES_IDETECTOROPERATIONSYSTEM_H__

#include "itypeoperationsystem.h"
#include <QString>
#include <QVector>

namespace coex
{
	// interface of detector operation system
	class IDetectorOperationSystem {
		public:
			virtual coex::ITypeOperationSystem* detect(QString path) = 0;
			virtual QString name() = 0;
			virtual QString author() = 0;
			virtual QVector<coex::ITypeOperationSystem *> getSupportsOS() = 0;
	};
}

#endif //__COEX_INTERFACES_IDETECTOROPERATIONSYSTEM_H__
