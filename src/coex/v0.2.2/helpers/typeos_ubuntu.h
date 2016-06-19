#ifndef __COEX_HELPERS_TYPEOS_UBUNTU_H__
#define __COEX_HELPERS_TYPEOS_UBUNTU_H__

#include "coex.h"
#include <QString>

class TypeOS_Ubuntu : public coex::ITypeOperationSystem {
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

#endif //__COEX_HELPERS_TYPEOS_UBUNTU_H__
