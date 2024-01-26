#include <iostream>

#include "adt.h"

using namespace std;

int main() {
    try {
        Array arr;
        arr.append(1);
        arr.append(2);
        arr.append(3);
        arr.append(4);
        arr.append(5);
        arr.display();
        arr.remove(4);
        arr.display();
        // arr.get(7);
    } catch (std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (std::bad_alloc &e) {
        std::cerr << e.what() << std::endl;
        return 2;
    }
    return 0;
}
