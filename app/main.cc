#include <fmt/format.h>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include <cxxopts.hpp>
#include "config.h"
#include <iostream>

using namespace std;
using json = nlohmann::json;

int main(int argc, char *argv[]) {

  cxxopts::Options options("MyProgram", "One line description of MyProgram");

  options.add_options()
      ("d,debug", "Enable debugging") // a bool parameter
      ("i,integer", "Int param", cxxopts::value<int>())
      ("f,file", "File name", cxxopts::value<std::string>())
      ("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"));

  cout << fmt::format("Welcome to {} {} !", project_name, project_version) << endl;

  auto result = options.parse(argc, argv);

  try {
    if (result["debug"].as<bool>()) {
      spdlog::set_level(spdlog::level::debug);
    }
  } catch (const cxxopts::exceptions::exception &e) {
    spdlog::error("cxxopts error: {}", e.what());
  }
  spdlog::debug("JSON: {}.{}.{}",
                NLOHMANN_JSON_VERSION_MAJOR,
                NLOHMANN_JSON_VERSION_MINOR,
                NLOHMANN_JSON_VERSION_PATCH);
  spdlog::debug("CXXOPTS: {}.{}.{}", CXXOPTS__VERSION_MAJOR, CXXOPTS__VERSION_MINOR, CXXOPTS__VERSION_PATCH);
  spdlog::debug("SPDLOG: {}.{}.{}", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);
  spdlog::debug("FMT: {}", FMT_VERSION);

  cout << "Creating json object ..." << endl;
  json j;
  j["pi"] = 3.141;
  j["happy"] = true;
  j["name"] = "Niels";
  j["nothing"] = nullptr;
  j["answer"]["everything"] = 42;
  j["list"] = { 1, 0, 2 };
  j["object"] = { {"currency", "USD"}, {"value", 42.99} };
  cout << "...done." << endl;

  return 0;
}
