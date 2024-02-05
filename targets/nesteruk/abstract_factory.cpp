#include <iostream>
#include <DrinkFactory.h>

using namespace std;

int main()
{
    DrinkFactory df;
    auto c = df.make_drink("coffee");
    auto t = df.make_drink("tea");
    return EXIT_SUCCESS;
}
