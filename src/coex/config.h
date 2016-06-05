#ifndef __COEX_CONFIG_H__
#define __COEX_CONFIG_H__

#include "coex.h"
#include <QString>

class Config : public coex::IConfig {
	public:
		virtual QString inputFolder() const;
		virtual QString outputFolder() const;
		virtual const coex::ITypeOperationSystem* typeOS() const;
		
		virtual void setInputFolder(QString path);
		virtual void setOutputFolder(QString path);
		virtual void setTypeOS(coex::ITypeOperationSystem* pTypeOS);
		
		virtual bool isUnknownOS();
		virtual bool isWindows();
		virtual bool isLinux();

		virtual bool getArgumentsValues(int, char**, QString);
		virtual bool isDebugEnable() const;
	private:
		coex::ITypeOperationSystem* m_pTypeOS;
		QString m_sInputFolder;
		QString m_sOutputFolder;
		
};

#endif // __COEX_CONFIG_H__
