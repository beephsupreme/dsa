cmake_minimum_required(VERSION 3.27)

project(project-name VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(LIBRARY_NAME mnr)
set(EXECUTABLE_NAME app)

add_subdirectory(src)
add_subdirectory(app)

