#include "task.h"

coex::ITask* createTask()
{
    return (coex::ITask*)(new TaskSearchGitRepository());
}
