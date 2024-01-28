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
  cout << "Min: " << arr.min() << endl;
  cout << "Max: " << arr.max() << endl;
  arr.reverse();
  arr.display();

  auto g = [&arr](int x) -> int {
    return arr.get(x);
  };

  for (auto i{0}; i < 5; i++) {
    cout << g(i) << endl;
  }
  arr.display();

  Rectangle r(10, 5);
  cout << "rectangle has area " << r.area() << endl;
  cout << "rectangle has perimeter " << r.perimeter() << endl;
  return 0;
}
