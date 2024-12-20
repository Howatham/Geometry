cmake_minimum_required(VERSION 3.27)
project(Geometry)

set(CMAKE_CXX_STANDARD 23)

add_executable(Geometry main.cpp
        src/circle.cpp
        src/line.cpp
        src/point.cpp
        src/polygon.cpp
        src/ray.cpp
        src/segment.cpp
        src/vector.cpp)
