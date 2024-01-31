cmake_minimum_required(VERSION 3.27)

project(dsa VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)
include(FetchContent)

add_git_submodule(external/json)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG v1.14.x
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)
add_subdirectory(configured)
