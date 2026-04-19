#ifndef MINI_BACKEND_SYSTEM_TASKSERVICE_H
#define MINI_BACKEND_SYSTEM_TASKSERVICE_H

#include "../Storage/ITaskStorage.h"
#include "../Model/Task.h"
#include <vector>

namespace backend {

    class TaskService {
    private:
        int nextId = 1;
        ITaskStorage& storage;

    public:
        explicit TaskService(ITaskStorage &st);
        void addTask(const std::string& title);
        [[nodiscard]] std::vector<Task> getTasks() const;
        void completeTask(int id) ;
        void deleteTaskById(int id);
        void deleteTaskByTitle(const std::string& t1);




    };
}




#endif //MINI_BACKEND_SYSTEM_TASKSERVICE_H
