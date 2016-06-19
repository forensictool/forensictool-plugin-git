#ifndef __COEX_INTERFACES_ICORE_H__
#define __COEX_INTERFACES_ICORE_H__

namespace coex
{

	// interface of running tasks
	class ICore
	{
		public:
			virtual void loadPluginsByPath(const QString &fullpathToFolder) = 0;
			virtual void loadPluginsFromSystem() = 0;
			virtual bool loadPlugin(const QString &fullpathToPlugin) = 0;
			virtual QVector<coex::ITask *> &tasks() = 0;
			virtual QVector<coex::IDetectorOperationSystem *> &detectors() = 0;
			virtual void setMaxThreads(int nMaxThreads) = 0;
			virtual void run(coex::IConfig *pConfig) = 0;
	};
}


#endif //__COEX_INTERFACES_ICORE_H__
