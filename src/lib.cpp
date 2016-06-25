#include "task.h"

forensictool::ITask* createTask()
{
    return (forensictool::ITask*)(new TaskSearchGitRepository());
}
