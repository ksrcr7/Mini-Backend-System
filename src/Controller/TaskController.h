#ifndef MINI_BACKEND_SYSTEM_TASKCONTROLLER_H
#define MINI_BACKEND_SYSTEM_TASKCONTROLLER_H

#include "../Service/TaskService.h"
#include "../Model/Task.h"

namespace backend{

    class TaskController {
    private:
            TaskService& service;

    public:
        struct Command{
            std::string action;
            std::vector<std::string> args;
        };
        explicit TaskController(TaskService& sv);
        Command pars(const std::string& input);



    };

}



#endif //MINI_BACKEND_SYSTEM_TASKCONTROLLER_H
