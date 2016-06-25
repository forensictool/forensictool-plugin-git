#ifndef __FORENSICTOOL_CONFIG_H__
#define __FORENSICTOOL_CONFIG_H__

#include "forensictool.h"
#include <QString>
#include <QMap>

class Config : public forensictool::IConfig {
	public:
		Config();
		
		// forensictool::IConfig
		virtual void setParameters(QStringList);
		virtual QString inputFolder() const;
		virtual QString outputFolder() const;
		virtual const forensictool::ITypeOperationSystem* typeOS() const;
		virtual void setInputFolder(QString path);
		virtual void setOutputFolder(QString path);
		virtual void setTypeOS(forensictool::ITypeOperationSystem* pTypeOS);
		virtual bool isDebugEnabled() const;
		virtual bool isUnknownOS() const;
		virtual bool isWindows() const;
		virtual bool isLinux() const;
		virtual bool isUnix() const;
		virtual bool isMacOS() const;
		virtual bool isIOS() const;
		virtual bool isAndroid() const;
		virtual bool isWindowsMobile() const;

	private:
		forensictool::ITypeOperationSystem* m_pTypeOS;
		QString m_sInputFolder;
		QString m_sOutputFolder;
		QStringList m_listParameters;
};

forensictool::IConfig* createConfig();

#endif //__FORENSICTOOL_CONFIG_H__
