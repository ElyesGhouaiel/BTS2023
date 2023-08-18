cmake_minimum_required(VERSION 3.5)

project(exo-2-essaie2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(exo-2-essaie2 main.cpp)

install(TARGETS exo-2-essaie2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
