#include "fmt/format.h"
#include "nlohmann/json.hpp"
#include "spdlog/spdlog.h"
#include "cxxopts.hpp"
#include "config.h"
#include <iostream>

using namespace std;
using json = nlohmann::json;

int main(int argc, char* argv[])
{

    cxxopts::Options options("dsa", "A project to learn Cmake, Data Structures and Algorithms");

    options.add_options()
        ("d,debug", "Enable debugging")
        ("j,json", "Demo JSON")
        ("h,help", "Print usage");

    cout << fmt::format("Welcome to {} {} !", project_name, project_version) << endl;

    cxxopts::ParseResult result;

    try {
        result = options.parse(argc, argv);
    } catch (const cxxopts::exceptions::exception& e) {
        spdlog::error("cxxopts: {}", e.what());
        return EXIT_FAILURE;
    }

    if (result.count("help")) {
        cout << options.help() << endl;
        return EXIT_SUCCESS;
    }

    if (result["debug"].as<bool>()) {
        spdlog::set_level(spdlog::level::debug);
    }

    spdlog::debug("JSON: {}.{}.{}",
        NLOHMANN_JSON_VERSION_MAJOR,
        NLOHMANN_JSON_VERSION_MINOR,
        NLOHMANN_JSON_VERSION_PATCH);
    spdlog::debug("CXXOPTS: {}.{}.{}", CXXOPTS__VERSION_MAJOR, CXXOPTS__VERSION_MINOR, CXXOPTS__VERSION_PATCH);
    spdlog::debug("SPDLOG: {}.{}.{}", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);
    spdlog::debug("FMT: {}", FMT_VERSION);

    if (result["json"].as<bool>()) {
        json j;
        j["pi"] = 3.1416;
        j["happy"] = true;
        j["name"] = "Mike";
        j["nothing"] = nullptr;
        j["answer"]["everything"] = 42;
        j["list"] = {1, 0, 2};
        j["object"] = {{"currency", "USD"}, {"value", 42.99}};
        cout << fmt::format("JSON obeject is being output via fmt::format:{}{}", '\n', j.dump(2)) << endl;
    }
}