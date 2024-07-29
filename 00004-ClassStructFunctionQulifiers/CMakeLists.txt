cmake_minimum_required(VERSION 3.26)
project(main)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_REQUIRED on)
set(CMAKE_CXX_EXTENSION on)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_REQUIRED on)
set(CMAKE_C_EXTENSION on)

add_executable(MAIN main.cpp include.cpp)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)
