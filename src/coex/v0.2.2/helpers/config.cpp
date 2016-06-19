#include "config.h"
#include <QDir>

Config::Config() {
	m_pTypeOS = NULL;
};

// ---------------------------------------------------------------------

void Config::setParameters(QStringList listParameters){
	m_listParameters = listParameters;
};

// ---------------------------------------------------------------------

QString Config::inputFolder() const {
	return m_sInputFolder;
};

// ---------------------------------------------------------------------

QString Config::outputFolder() const {
	return m_sOutputFolder;
};

// ---------------------------------------------------------------------

const coex::ITypeOperationSystem* Config::typeOS() const {
	return m_pTypeOS;
};

// ---------------------------------------------------------------------

void Config::setInputFolder(QString path) {
	m_sInputFolder = path;
};

// ---------------------------------------------------------------------

void Config::setOutputFolder(QString path) {
	if(!QDir(path).exists()){
        QDir().mkdir(path);
    }
	m_sOutputFolder = path;
};

// ---------------------------------------------------------------------

void Config::setTypeOS(coex::ITypeOperationSystem* pTypeOS) {
	m_pTypeOS = pTypeOS;
};

// ---------------------------------------------------------------------

bool Config::isDebugEnabled() const {
	return m_listParameters.contains("--debug");
}

// ---------------------------------------------------------------------

bool Config::isUnknownOS() const {
	return (m_pTypeOS != NULL && m_pTypeOS->platform() == "");
};

// ---------------------------------------------------------------------

bool Config::isWindows() const {
	return (m_pTypeOS != NULL && m_pTypeOS->platform() == "Windows");
};

// ---------------------------------------------------------------------

bool Config::isLinux() const {
	return (m_pTypeOS != NULL && m_pTypeOS->platform() == "Linux");
};

// ---------------------------------------------------------------------

bool Config::isUnix() const{
	return (m_pTypeOS != NULL && m_pTypeOS->platform() == "Unix");
}

// ---------------------------------------------------------------------

bool Config::isMacOS() const{
	return (m_pTypeOS != NULL && m_pTypeOS->platform() == "MacOS");
}

// ---------------------------------------------------------------------

bool Config::isIOS() const{
	return (m_pTypeOS != NULL && m_pTypeOS->platform() == "iOS");
}

// ---------------------------------------------------------------------

bool Config::isAndroid() const{
	return (m_pTypeOS != NULL && m_pTypeOS->platform() == "Android");
}

// ---------------------------------------------------------------------

bool Config::isWindowsMobile() const{
	return (m_pTypeOS != NULL && m_pTypeOS->platform() == "WindowsMobile");
}

// ---------------------------------------------------------------------

coex::IConfig* createConfig() {
	return (coex::IConfig *) new Config();
}

// ---------------------------------------------------------------------
