cmake_minimum_required(VERSION 3.20)

project(esercitazione6)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow")

add_executable(test_unidirected_edge
    test_unidirected_edge.cpp
)

add_test(NAME edge_test COMMAND test_unidirected_edge)

add_executable(test_unidirected_graph
    test_unidirected_graph.cpp
)

add_test(NAME graph_test COMMAND test_unidirected_graph)

enable_testing()