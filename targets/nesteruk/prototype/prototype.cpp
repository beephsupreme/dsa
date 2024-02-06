#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <utility>
#include <Address.h>
#include <Contact.h>
#include <EmployeeFactory.h>

using namespace std;

int main()
{
    auto mike = EmployeeFactory::NewMainOfficeEmployee("Mike", 123);
    auto jim = EmployeeFactory::NewAuxOfficeEmployee("Jim", 42);
    cout << *mike << endl;
    cout << *jim << endl;
    return EXIT_SUCCESS;
}

//Dmitri say:
// 4. Boost Serialization
// too much work in getting the copying working
// Par for the course
