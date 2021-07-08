cmake_minimum_required(VERSION 3.16)
project(Realocacao_Interplanetaria)

set(CMAKE_CXX_STANDARD 11)

add_executable(Realocacao_Interplanetaria src/main.cpp include/Queue.h src/Queue.cpp include/Element.h src/Element.cpp include/Testcases.h src/Testcases.cpp)