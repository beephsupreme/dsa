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

using namespace std;


int main() {
  Address addr{"123 Main St", "Anaheim", 42};
  cout << addr << endl;
  Contact cnt {"Mike", &addr};
  cout << cnt << endl;

  return EXIT_SUCCESS;
}


//
//struct EmployeeFactory
//{
//    static Contact main;
//    static Contact aux;
//
//    static unique_ptr<Contact> NewMainOfficeEmployee(string name, int suite)
//    {
//        //static Contact p{ "", new Address{ "123 East Dr", "London", 0 } };
//        return NewEmployee(name, suite, main);
//    }
//
//    static unique_ptr<Contact> NewAuxOfficeEmployee(string name, int suite)
//    {
//        return NewEmployee(name, suite, aux);
//    }
//
//private:
//    static unique_ptr<Contact> NewEmployee(string name, int suite, Contact& proto)
//    {
//        auto result = make_unique<Contact>(proto);
//        result->name = name;
//        result->address->suite = suite;
//        return result;
//    }
//};

//Contact EmployeeFactory::main{ "", new Address{ "123 East Dr", "London", 0 } };
//Contact EmployeeFactory::aux{ "", new Address{ "123B East Dr", "London", 0 } };

//int main_3423()
//{
// this is tedious
// Contact john{ "John Doe", new Address{"123 East Dr", "London"} };
// Contact jane{ "Jane Doe", new Address{"123 East Dr", "London"} };

//    auto addr = new Address{ "123 East Dr", "London", 0 /* ? */ };

//Contact john{ "John Doe", addr };
//john.address->suite = 123;
//Contact jane{ "Jane Doe", addr };
//jane.address->suite = 124;

//Contact jane2{ jane }; // shallow copy
//jane2.address->suite = 555;



//
//std::cout << jane2 << std::endl;

// whenever an address is needed, make a copy
/*Contact john{ "John Doe", new Address{*addr} };
john.address->suite = 123;

Contact jane{ "Jane Doe", new Address{*addr} };
jane.address->suite = 125;

cout << john << "\n" << jane << endl;*/

// much better. let's list employees
//Contact employee{ "Unknown", new Address{"628 Happy St", "Joy", 0} };

//// we can use this prototype to create john and jane
//Contact john{ employee };
//john.name = "John Doe";
//john.address->suite = 123;

//Contact jane{ employee };
//jane.name = "Jane Doe";
//jane.address->suite = 125;

//cout << john << "\n" << jane << "\n";

//delete addr;

// 4. Boost Serialization

// too much work in getting the copying working


//auto john = EmployeeFactory::NewAuxOfficeEmployee("John Doe", 123);
//auto jane = EmployeeFactory::NewMainOfficeEmployee("Jane Doe", 125);

//cout << *john << "\n" << *jane << "\n"; // note the stars here

//    delete addr;
//
//    getchar();
//    return 0;
//}
