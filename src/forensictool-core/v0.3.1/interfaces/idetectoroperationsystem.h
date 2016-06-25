#ifndef __FORENSICTOOL_INTERFACES_IDETECTOROPERATIONSYSTEM_H__
#define __FORENSICTOOL_INTERFACES_IDETECTOROPERATIONSYSTEM_H__

#include "itypeoperationsystem.h"
#include <QString>
#include <QVector>

namespace forensictool
{
	// interface of detector operation system
	class IDetectorOperationSystem {
		public:
			virtual forensictool::ITypeOperationSystem* detect(QString path) = 0;
			virtual QString name() = 0;
			virtual QString author() = 0;
			virtual QVector<forensictool::ITypeOperationSystem *> getSupportsOS() = 0;
	};
}

#endif //__FORENSICTOOL_INTERFACES_IDETECTOROPERATIONSYSTEM_H__
