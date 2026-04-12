#ifndef MINI_BACKEND_SYSTEM_ITASKSTORAGE_H
#define MINI_BACKEND_SYSTEM_ITASKSTORAGE_H

#include "../Model/Task.h"
#include <vector>


class ITaskStorage {

public:
    virtual void add(const backend::Task& task) = 0;
    [[nodiscard]] virtual std::vector<backend::Task> getAll() const = 0;
    virtual void update(const backend::Task& task) = 0;
    virtual ~ITaskStorage() = default;

};












#endif //MINI_BACKEND_SYSTEM_ITASKSTORAGE_H
