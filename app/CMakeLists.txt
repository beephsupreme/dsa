add_executable(app main.cc)
target_link_libraries(app PUBLIC
        adt
        nlohmann_json::nlohmann_json
        fmt::fmt
        spdlog::spdlog
        cxxopts::cxxopts)
