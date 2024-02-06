#pragma once
#include <Contact.h>
#include <string>
#include <utility>

struct EmployeeFactory {

    static std::unique_ptr<Contact> NewMainOfficeEmployee(std::string name, int suite)
    {
        static Contact main{"", new Address{"123 Main Street", "Anaheim", 0}};
        return NewEmployee(std::move(name), suite, main);
    }

    static std::unique_ptr<Contact> NewAuxOfficeEmployee(std::string name, int suite)
    {
        static Contact aux{"", new Address{"101 First Street", "Santa Ana", 0}};
        return NewEmployee(std::move(name), suite, aux);
    }

private:
    static std::unique_ptr<Contact> NewEmployee(std::string name, int suite, Contact& proto)
    {
        auto result = std::make_unique<Contact>(proto);
        result->name = std::move(name);
        result->address->suite = suite;
        return result;
    }
};