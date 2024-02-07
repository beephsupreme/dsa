#pragma once

#include <string>
#include <iostream>

class PersonBuilder;

class Person {
 private:
  std::string street_address;
  std::string post_code;
  std::string city;

  std::string company_name;
  std::string position;
  int annual_income{0};

  Person() {
    std::cout << "Person created..." << std::endl;
  }

 public:
  ~Person() {
    std::cout << "Person destroyed ..." << std::endl;
  }

  static PersonBuilder create();

  friend std::ostream &operator<<(std::ostream &os, const Person &person);

  friend class PersonBuilder;
  friend class PersonJobBuilder;
  friend class PersonAddressBuilder;

};

