#include "InMemoryTaskStorage.h"
#include <algorithm>

static bool isAllSpace(const std::string& st){
    return std::all_of(st.begin(),st.end(),[](unsigned char c){
        return std::isspace(c);
    });
}

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

bool backend::InMemoryTaskStorage::removebyId(int id) {
    auto it = std::find_if(tasks.begin(),tasks.end(),
                           [&](Task& task){return task.id == id;});

    if(it == tasks.end())
        return false;

    tasks.erase(it);
    return true;
}

bool backend::InMemoryTaskStorage::removebyTitle(const std::string& t1) {
    if(t1.empty() || isAllSpace(t1))
        return false;

    auto it = std::find_if(tasks.begin(),tasks.end(),
                           [&](Task& t){return t.title == t1;});

    if(it == tasks.end())
        return false;

    tasks.erase(it);
    return true;


}
