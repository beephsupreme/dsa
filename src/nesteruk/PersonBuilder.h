#pragma once

#include <Person.h>

class PersonJobBuilder;
class PersonAddressBuilder;

class PersonBuilderBase {
 protected:
  Person &person;
 public:
  explicit PersonBuilderBase(Person &person) : person{person} {
  }
  [[nodiscard]] PersonAddressBuilder lives() const;
  [[nodiscard]] PersonJobBuilder works() const;
  operator Person() const // NOLINT(*-explicit-constructor)
  {
    return person;
  }
};

class PersonBuilder : public PersonBuilderBase {
 public:
  PersonBuilder() : PersonBuilderBase{p} {
  }
 private:
  Person p;
};

