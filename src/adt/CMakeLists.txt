add_library(adt STATIC adt.cpp)
target_include_directories(adt PUBLIC
        "./"
        "${CMAKE_BINARY_DIR}/configured_files/include"
)
