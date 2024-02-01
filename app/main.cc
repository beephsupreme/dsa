#include <iostream>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include <cxxopts.hpp>
#include <fmt/format.h>
#include "config.h"

using namespace std;

int main() {
  cout << project_name << " " << project_version << endl;

  cout << "JSON: "
       << NLOHMANN_JSON_VERSION_MAJOR << "."
       << NLOHMANN_JSON_VERSION_MINOR << "."
       << NLOHMANN_JSON_VERSION_PATCH << endl;

  cout << "CXXOPTS: "
       << CXXOPTS__VERSION_MAJOR << "."
       << CXXOPTS__VERSION_MINOR << "."
       << CXXOPTS__VERSION_PATCH << endl;

  cout << "SPDLOG: "
       << SPDLOG_VER_MAJOR << "."
       << SPDLOG_VER_MINOR << "."
       << SPDLOG_VER_PATCH << endl;

  cout << "FMT: " << FMT_VERSION << endl;

  return 0;
}
