#ifndef MINI_BACKEND_SYSTEM_TASKCONTROLLER_H
#define MINI_BACKEND_SYSTEM_TASKCONTROLLER_H

#include "../Service/TaskService.h"
#include "../Model/Task.h"

namespace backend{

    class TaskController {
    private:
            TaskService& service;

    public:
        explicit TaskController(TaskService& sv);



    };

}



#endif //MINI_BACKEND_SYSTEM_TASKCONTROLLER_H
