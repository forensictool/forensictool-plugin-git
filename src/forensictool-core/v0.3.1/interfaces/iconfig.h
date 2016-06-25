#ifndef __FORENSICTOOL_INTERFACES_ICONFIG_H__
#define __FORENSICTOOL_INTERFACES_ICONFIG_H__

#include "itypeoperationsystem.h"
#include <QString>
#include <QStringList>

namespace forensictool
{
	// interface of config
	class IConfig {
		public:
			virtual void setParameters(QStringList) = 0;
			virtual QString inputFolder() const = 0;
			virtual QString outputFolder() const = 0;
			virtual const forensictool::ITypeOperationSystem* typeOS() const = 0;
			virtual void setInputFolder(QString path) = 0;
			virtual void setOutputFolder(QString path) = 0;
			virtual void setTypeOS(forensictool::ITypeOperationSystem*) = 0;
			virtual bool isDebugEnabled() const = 0;
			virtual bool isUnknownOS() const = 0;
			virtual bool isWindows() const = 0;
			virtual bool isLinux() const = 0;
			virtual bool isUnix() const = 0;
			virtual bool isMacOS() const = 0;
			virtual bool isIOS() const = 0;
			virtual bool isAndroid() const = 0;
			virtual bool isWindowsMobile() const = 0;
	};
}

#endif // __FORENSICTOOL_INTERFACES_ICONFIG_H__
