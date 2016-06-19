#include "typeos_ubuntu.h"


TypeOS_Ubuntu::TypeOS_Ubuntu(QString version){
	m_sPlatform = "Ubuntu";
	m_sVersion = version;
};

QString TypeOS_Ubuntu::platform() const{
	return m_sPlatform;
};

void TypeOS_Ubuntu::setPlatform(QString platform){
	m_sPlatform = platform;
};

QString TypeOS_Ubuntu::version() const{
	return m_sVersion;
};

void TypeOS_Ubuntu::setVersion(QString version){
	m_sVersion = version;
};

QString TypeOS_Ubuntu::toString() const{
	return m_sPlatform + " " + m_sVersion;
};
