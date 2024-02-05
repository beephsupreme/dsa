#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

int main()
{
    auto p = Point::Factory.NewPolar(5, M_PI_4);
    cout << p << endl;

    auto c = Point::Factory.NewCartesian(5, 4);
    cout << c << endl;

    return EXIT_SUCCESS;
}
