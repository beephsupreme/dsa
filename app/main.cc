#include <iostream>
#include <nlohmann/json.hpp>
#include "config.h"

using namespace std;

int main() {
  cout << project_name << " " << project_version << endl;
  cout << "JSON Lib version "
       << NLOHMANN_JSON_VERSION_MAJOR << "."
       << NLOHMANN_JSON_VERSION_MINOR << "."
       << NLOHMANN_JSON_VERSION_PATCH << endl;
  return 0;
}
