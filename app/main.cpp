#include <iostream>
#include <HtmlElement.h>
#include <HtmlBuilder.h>

using namespace std;

int main()
{
    HtmlElement ele = HtmlElement::build("ul")
        .add_child("li", "hello")
        .add_child("li", "world");
    cout << ele.str() << endl;
    return EXIT_SUCCESS;
}
