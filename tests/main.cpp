#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include<iostream>
#include "adt.h"
#include "recursion.h"

TEST_CASE("ADT Array Append", "[append]") {
  Array arr(0);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 0);
  arr.append(1);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 1);
  arr.append(2);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 2);
  arr.append(3);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 3);
  arr.append(4);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 4);
  arr.append(5);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 5);
  arr.append(6);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 6);
  arr.append(7);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 7);
  arr.append(8);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 8);
  arr.append(9);
  REQUIRE(arr.getSize() == 16);
  REQUIRE(arr.getLength() == 9);
  arr.append(10);
  REQUIRE(arr.getSize() == 16);
  REQUIRE(arr.getLength() == 10);
}

TEST_CASE("ADT Array At", "[at]") {
  Array arr(0);
  arr.append(1);
  arr.append(2);
  arr.append(3);
  arr.append(4);
  arr.append(5);
  arr.append(6);
  arr.append(7);
  arr.append(8);
  arr.append(9);
  arr.append(10);
  REQUIRE(arr.at(0) == 1);
  REQUIRE(arr.at(1) == 2);
  REQUIRE(arr.at(2) == 3);
  REQUIRE(arr.at(3) == 4);
  REQUIRE(arr.at(4) == 5);
  REQUIRE(arr.at(5) == 6);
  REQUIRE(arr.at(6) == 7);
  REQUIRE(arr.at(7) == 8);
  REQUIRE(arr.at(8) == 9);
  REQUIRE(arr.at(9) == 10);
  REQUIRE(arr.getSize() == 16);
  REQUIRE(arr.getLength() == 10);
}

  TEST_CASE("ADT Array Insert", "[insert]") {
  Array arr(0);
  arr.insert(1, 1);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 1);
  arr.insert(2, 1);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 2);
  arr.insert(3, 1);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 3);
  arr.insert(4, 1);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 4);
  arr.insert(5, 1);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 5);
  arr.insert(6, 1);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 6);
  arr.insert(7, 1);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 7);
  arr.insert(8, 1);
  REQUIRE(arr.getSize() == 8);
  REQUIRE(arr.getLength() == 8);
  arr.insert(9, 1);
  REQUIRE(arr.getSize() == 16);
  REQUIRE(arr.getLength() == 9);
  arr.insert(10, 1);
  REQUIRE(arr.getSize() == 16);
  REQUIRE(arr.getLength() == 10);
}
