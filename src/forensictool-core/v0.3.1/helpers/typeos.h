#ifndef __FORENSICTOOL_TYPEOS_H__
#define __FORENSICTOOL_TYPEOS_H__

#include "forensictool.h"
#include <QString>

class TypeOS : public forensictool::ITypeOperationSystem {
	public:
		virtual QString platform() const;
		virtual void setPlatform(QString);

		virtual QString version() const;
		virtual void setVersion(QString);

		virtual QString toString() const;
};

#endif // __FORENSICTOOL_TYPEOS_H__
