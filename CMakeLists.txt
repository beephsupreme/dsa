cmake_minimum_required(VERSION 3.27)

project(dsa VERSION 1.0.0 LANGUAGES C CXX)

#set(CMAKE_C_COMPILER "/opt/homebrew/bin/gcc-13")
#set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-13")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_TESTING "Enable a Unit Testing Build" ON)
option(ENABLE_WARNINGS "Enable to add warnings to a target." OFF)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warnings as errors." OFF)
option(ENABLE_SANITIZE_ADDR "Enable to detect memory errors." OFF)
option(ENABLE_SANITIZE_UNDEF "Enable to detect/trace undefined behavior errors." OFF)
option(LOAD_DOXYGEN "Turn Doxygen ON/OFF" OFF)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)
include(FetchContent)

if (LOAD_DOXYGEN)
    include(Docs)
endif ()

if (ENABLE_WARNINGS)
    include(Warnings)
endif ()

if (ENABLE_SANITIZE_ADDR OR ENABLE_SANITIZE_UNDEF)
    include(Sanitizers)
    add_sanitizer_flags()
endif ()

FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG v3.11.3
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(nlohmann_json)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 10.2.1
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(fmt)

set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(SPDLOG_FMT_EXTERNAL ON)
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog
        GIT_TAG v1.13.0
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
        cxxopts
        GIT_REPOSITORY https://github.com/jarro2783/cxxopts
        GIT_TAG v3.1.1
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(cxxopts)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG v1.14.x
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src)
add_subdirectory(targets)
add_subdirectory(tests)
add_subdirectory(configured)
