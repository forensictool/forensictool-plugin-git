#ifndef __FORENSICTOOL_HELPERS_TYPEOS_UBUNTU_H__
#define __FORENSICTOOL_HELPERS_TYPEOS_UBUNTU_H__

#include "forensictool.h"
#include <QString>

class TypeOS_Ubuntu : public forensictool::ITypeOperationSystem {
	public:
		TypeOS_Ubuntu(QString version);
		virtual QString platform() const;
		virtual void setPlatform(QString platform);
		virtual QString version() const;
		virtual void setVersion(QString version);
		virtual QString toString() const;
	private:
		QString m_sPlatform;
		QString m_sVersion;
};

#endif //__FORENSICTOOL_HELPERS_TYPEOS_UBUNTU_H__
