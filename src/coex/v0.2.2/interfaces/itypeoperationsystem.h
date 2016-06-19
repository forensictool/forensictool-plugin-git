#ifndef __COEX_INTERFACES_ITYPEOPERATIONSYSTEM_H__
#define __COEX_INTERFACES_ITYPEOPERATIONSYSTEM_H__

#include <QString>

namespace coex
{
	// interface of type operation system
	class ITypeOperationSystem {
		public:
			// platform: "Windows" or "Linux"
			virtual QString platform() const = 0;
			virtual void setPlatform(QString platform) = 0;
			
			// for platform "Windows" version can be "95" or "98" or "XP" or "Vista" or "7" or "8"
			virtual QString version() const = 0;
			virtual void setVersion(QString version) = 0;
	};
};


#endif //__COEX_INTERFACES_ITYPEOPERATIONSYSTEM_H__
