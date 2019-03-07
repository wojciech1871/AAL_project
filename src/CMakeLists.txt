cmake_minimum_required(VERSION 2.6)
project(AAL_LS_lamana)

include_directories(${MyProject_SOURCE_DIR}/include)

add_executable(prog main.cpp Point.cpp Vertex.cpp PointsGenerator.cpp MyAlgorithm.cpp)

