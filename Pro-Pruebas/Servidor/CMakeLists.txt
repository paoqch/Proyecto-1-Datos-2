cmake_minimum_required(VERSION 3.17)
project(Servidor)

set(CMAKE_CXX_STANDARD 20)

add_executable(Servidor main.cpp Servidor.cpp Servidor.h FacadeMemory.cpp FacadeMemory.h Node.h MemoryBlock.cpp MemoryBlock.h json.hpp Node.cpp)