cmake_minimum_required(VERSION 3.20)
project(esercizio2c)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE CXX FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(SOURCES esercizio2c.cpp)

add_executable(proges2 ${SOURCES})
