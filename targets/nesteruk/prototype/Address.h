#pragma once

#include<ostream>
#include <string>

struct Address {
  std::string street;
  std::string city;
  int suite;

  Address(std::string street, std::string city, const int suite)
      : street{std::move(street)},
        city{std::move(city)},
        suite{suite} {
  }

  friend std::ostream &operator<<(std::ostream &os, const Address &obj) {
    return os
        << "street: " << obj.street
        << " city: " << obj.city
        << " suite: " << obj.suite;
  }
};
