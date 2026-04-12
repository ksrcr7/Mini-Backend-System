#ifndef MINI_BACKEND_SYSTEM_TASK_H
#define MINI_BACKEND_SYSTEM_TASK_H

#include <string>

namespace backend {

    struct Task{
        int id;
        std::string title;
        bool done = false;

    };
}












#endif //MINI_BACKEND_SYSTEM_TASK_H
