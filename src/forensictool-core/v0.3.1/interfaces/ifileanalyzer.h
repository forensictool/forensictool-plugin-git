#ifndef __FORENSICTOOL_INTERFACES_IFILEANALYZER_H__
#define __FORENSICTOOL_INTERFACES_IFILEANALYZER_H__

#include <QString>
#include <QStringList>
#include <QMap>

namespace forensictool
{
	// interface of file analizer
	class IFileAnalyzer
	{
		public:
			virtual QString help() = 0;
			virtual QString name() = 0;
			virtual QStringList authors() = 0;
			virtual QString description() = 0;
			virtual QString license() = 0;
			virtual QString licenseFull() = 0;

			virtual bool execute(QString filepath, QMap<QString, QString> &result) = 0;
	};
}

#endif // __FORENSICTOOL_INTERFACES_IFILEANALYZER_H__
