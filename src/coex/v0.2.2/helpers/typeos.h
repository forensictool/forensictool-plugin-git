#ifndef __COEX_TYPEOS_H__
#define __COEX_TYPEOS_H__

#include "coex.h"
#include <QString>

class TypeOS : public coex::ITypeOperationSystem {
	public:
		virtual QString platform() const;
		virtual void setPlatform(QString);

		virtual QString version() const;
		virtual void setVersion(QString);

		virtual QString toString() const;
};

#endif // __COEX_TYPEOS_H__
