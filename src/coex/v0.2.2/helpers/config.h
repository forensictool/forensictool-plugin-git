#ifndef __COEX_CONFIG_H__
#define __COEX_CONFIG_H__

#include "coex.h"
#include <QString>
#include <QMap>

class Config : public coex::IConfig {
	public:
		Config();
		
		// coex::IConfig
		virtual void setParameters(QStringList);
		virtual QString inputFolder() const;
		virtual QString outputFolder() const;
		virtual const coex::ITypeOperationSystem* typeOS() const;
		virtual void setInputFolder(QString path);
		virtual void setOutputFolder(QString path);
		virtual void setTypeOS(coex::ITypeOperationSystem* pTypeOS);
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
		coex::ITypeOperationSystem* m_pTypeOS;
		QString m_sInputFolder;
		QString m_sOutputFolder;
		QStringList m_listParameters;
};

coex::IConfig* createConfig();

#endif //__COEX_CONFIG_H__
