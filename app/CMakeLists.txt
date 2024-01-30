add_executable(app main.cpp
        ../boost_tests/test1.cpp)
target_link_libraries(app PUBLIC
        recursion
        essentials
        adt
        nlohmann_json)
