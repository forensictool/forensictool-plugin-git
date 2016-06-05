#include "config.h"
#include <QSettings>



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
	m_sOutputFolder = path;
};

// ---------------------------------------------------------------------

void Config::setTypeOS(coex::ITypeOperationSystem* pTypeOS) {
	m_pTypeOS = pTypeOS;
};

// ---------------------------------------------------------------------

bool Config::isUnknownOS() {
	return false;
};

// ---------------------------------------------------------------------

bool Config::isWindows() {
	return true;
};

// ---------------------------------------------------------------------

bool Config::isLinux() {
	return true;
};

// ---------------------------------------------------------------------

bool Config::getArgumentsValues(int, char**, QString) {
	return true;
};

// ---------------------------------------------------------------------

bool Config::isDebugEnable() const {
	return true;
};
