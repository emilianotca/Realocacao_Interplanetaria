cmake_minimum_required(VERSION 3.16)
project(Realocacao_Interplanetaria)

set(CMAKE_CXX_STANDARD 11)

add_executable(Realocacao_Interplanetaria
        src/main.cpp
        include/Element.h
        src/Element.cpp
        include/Testcases.h
        src/Testcases.cpp
        include/Queue_Cell.h
        src/Queue_Cell.cpp
        include/Queue.h
        src/Queue.cpp
        include/Linked_Queue.h
        src/Linked_Queue.cpp)