#ifndef MINI_BACKEND_SYSTEM_INMEMORYTASKSTORAGE_H
#define MINI_BACKEND_SYSTEM_INMEMORYTASKSTORAGE_H

#include "ITaskStorage.h"
#include <vector>

namespace backend{

    class InMemoryTaskStorage : public ITaskStorage {
    private:
        std::vector<Task> tasks;

    public:
        void add(const backend::Task& task) override;
        std::vector<backend::Task> getAll() const override;
        void update(const backend::Task& task) override;


    };
}




#endif //MINI_BACKEND_SYSTEM_INMEMORYTASKSTORAGE_H
