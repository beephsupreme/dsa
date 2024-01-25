#include <iostream>

#include "adt.h"

using namespace std;

int main() {
  Array arr(50);
  arr.append(1);
  arr.append(2);
  arr.append(3);
  arr.append(4);
  arr.append(5);
  arr.get(7);
  return 0;
}
