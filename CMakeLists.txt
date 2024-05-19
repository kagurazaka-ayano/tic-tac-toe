cmake_minimum_required(VERSION 3.27)
project(tictactoe)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp")
set(INCLUDE "include")

include_directories(${INCLUDE})

add_executable(${PROJECT_NAME} ${SOURCES})

