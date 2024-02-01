#include <fmt/format.h>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include <cxxopts.hpp>
#include "config.h"
#include <iostream>

using namespace std;

int main() {

  std::string s = fmt::format("{} {}", project_name, project_version);
  cout << s << endl;

  s = fmt::format("JSON: {}.{}.{}",
                  NLOHMANN_JSON_VERSION_MAJOR,
                  NLOHMANN_JSON_VERSION_MINOR,
                  NLOHMANN_JSON_VERSION_PATCH);
  cout << s << endl;

  s = fmt::format("CXXOPTS: {}.{}.{}", CXXOPTS__VERSION_MAJOR, CXXOPTS__VERSION_MINOR, CXXOPTS__VERSION_PATCH);
  cout << s << endl;

  s = fmt::format("SPDLOG: {}.{}.{}", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);
  cout << s << endl;

  s = fmt::format("FMT: {}", FMT_VERSION);
  cout << s << endl;

  return 0;
}
