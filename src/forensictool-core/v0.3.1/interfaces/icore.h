#ifndef __FORENSICTOOL_INTERFACES_ICORE_H__
#define __FORENSICTOOL_INTERFACES_ICORE_H__

namespace forensictool
{
	// interface of running tasks
	class ICore
	{
		public:
			virtual void loadPluginsByPath(const QString &fullpathToFolder) = 0;
			virtual void loadPluginsFromSystem() = 0;
			virtual bool loadPlugin(const QString &fullpathToPlugin) = 0;
			virtual QVector<forensictool::ITask *> &tasks() = 0;
			virtual QVector<forensictool::IDetectorOperationSystem *> &detectors() = 0;
			virtual void setMaxThreads(int nMaxThreads) = 0;
			virtual void run(forensictool::IConfig *pConfig) = 0;
	};
}


#endif //__FORENSICTOOL_INTERFACES_ICORE_H__
