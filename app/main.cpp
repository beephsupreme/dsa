#include <iostream>
#include "adt.h"
#include "rectangle.h"

using namespace std;

int main() {
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
