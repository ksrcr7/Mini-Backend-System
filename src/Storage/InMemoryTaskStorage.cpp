#include "InMemoryTaskStorage.h"
#include <algorithm>

void backend::InMemoryTaskStorage::add(const backend::Task &task) {
    tasks.emplace_back(task);
}

std::vector<backend::Task> backend::InMemoryTaskStorage::getAll() const {
    return tasks;
}

void backend::InMemoryTaskStorage::update(const backend::Task &task) {
    auto it = std::find_if(tasks.begin(),tasks.end(),
                           [&](const Task& t){
                               return t.id == task.id;
    });

    if(it != tasks.end()){
        *it = task;
    }



}

backend::Task *backend::InMemoryTaskStorage::findbyId(int id) {
    auto it = std::find_if(tasks.begin(),tasks.end(),
                 [&](Task& task){return task.id == id;});

    if(it == tasks.end()){
        return nullptr;
    }

    return &(*it);




}
