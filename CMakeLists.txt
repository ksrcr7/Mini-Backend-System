cmake_minimum_required(VERSION 3.27)
project(Mini_Backend_System)

set(CMAKE_CXX_STANDARD 23)



add_executable(Mini_Backend_System src/main.cpp
        src/Controller/TaskController.cpp
        src/Controller/TaskController.h
        src/Service/TaskService.cpp
        src/Service/TaskService.h
        src/Storage/ITaskStorage.h
        src/Storage/InMemoryTaskStorage.cpp
        src/Storage/InMemoryTaskStorage.h
        src/Utils/JsonUtils.h
        src/Model/Task.h)
