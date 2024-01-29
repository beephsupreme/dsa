#include <iostream>
#include <nlohmann/json.hpp>
#include "adt.h"
#include "config.h"

using namespace std;

int main() {
  cout << project_name << " " << project_version << endl;
  cout << "JSON Lib version "
       << NLOHMANN_JSON_VERSION_MAJOR << "."
       << NLOHMANN_JSON_VERSION_MINOR << "."
       << NLOHMANN_JSON_VERSION_PATCH << endl;
  Array arr;
  arr.append(23);
  arr.append(24);
  arr.append(32);
  arr.append(8);
  arr.append(42);
  arr.display();
  cout << (arr.isSorted() ? "sorted" : "not sorted") << endl;
  arr.sort();
  arr.display();
  cout << (arr.isSorted() ? "sorted" : "not sorted") << endl;
  return 0;
}
