#include <iostream>

#include "adt.h"

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
    return 0;
}
