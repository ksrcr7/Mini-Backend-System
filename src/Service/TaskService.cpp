

#include "TaskService.h"
#include <stdexcept>
#include <algorithm>
#include <cctype>

backend::TaskService::TaskService(ITaskStorage &st) : storage(st),nextId(1){}

static bool isAllSpace(const std::string& st){
    return std::all_of(st.begin(),st.end(),[](unsigned char c){
        return std::isspace(c);
    });
}

void backend::TaskService::addTask(const std::string &title) {

    if(title.empty()){
        throw std::invalid_argument("Title can not be empty.");
    }

    if(isAllSpace(title)){
        throw std::invalid_argument("Title can not be only space.");
    }

    Task task;
    task.title = title;
    task.id = nextId;
    task.done = false;

    ++nextId;

    storage.add(task);
}

std::vector<backend::Task> backend::TaskService::getTasks() const {
    return storage.getAll();
}

void backend::TaskService::completeTask(int id)  {

    auto task = storage.findbyId(id);
    if(!task){
        throw std::out_of_range("Task not found.");
    }
    task->done = true;

}

void backend::TaskService::deleteTask(int id) {
    if(!storage.removebyId(id)){
        throw std::out_of_range("Task not found.");
    }

}


