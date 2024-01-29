add_executable(app main.cpp)
target_link_libraries(app PUBLIC
        recursion
        essentials
        adt
        nlohmann_json)
