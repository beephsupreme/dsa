add_executable(unit-tests main.cpp)
target_include_directories(unit-tests PUBLIC "./")
target_link_libraries(unit-tests PUBLIC recursion arrays essentials adt Catch2::Catch2)
