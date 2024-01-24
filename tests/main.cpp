#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include<iostream>
#include "adt.h"
#include "recursion.h"

TEST_CASE("ADT Array At/Append", "[at-append]") {
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

  TEST_CASE("ADT Array Insert @ Back", "[insert-back]") {
  Array arr(0);
  arr.insert(1, 0);
  arr.insert(2, 1);
  arr.insert(3, 2);
  arr.insert(4, 3);
  arr.insert(5, 4);
  arr.insert(6, 5);
  arr.insert(7, 6);
  arr.insert(8, 7);
  arr.insert(9, 8);
  arr.insert(10, 9);
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

  TEST_CASE("ADT Array Insert @ Front", "[insert-front]") {
  Array arr(0);
  arr.insert(1, 0);
  arr.insert(2, 0);
  arr.insert(3, 0);
  arr.insert(4, 0);
  arr.insert(5, 0);
  arr.insert(6, 0);
  arr.insert(7, 0);
  arr.insert(8, 0);
  arr.insert(9, 0);
  arr.insert(10, 0);
  REQUIRE(arr.at(0) == 10);
  REQUIRE(arr.at(1) == 9);
  REQUIRE(arr.at(2) == 8);
  REQUIRE(arr.at(3) == 7);
  REQUIRE(arr.at(4) == 6);
  REQUIRE(arr.at(5) == 5);
  REQUIRE(arr.at(6) == 4);
  REQUIRE(arr.at(7) == 3);
  REQUIRE(arr.at(8) == 2);
  REQUIRE(arr.at(9) == 1);
  REQUIRE(arr.getSize() == 16);
  REQUIRE(arr.getLength() == 10);
}

TEST_CASE("ADT Array Insert @ Will", "[insert-will]") {
  Array arr(0);
  arr.append(1);
  arr.append(2);
  arr.append(3);
  arr.append(4);
  arr.append(5);
  arr.insert(6, 0);
  arr.insert(7, 2);
  arr.insert(8, 4);
  arr.insert(9, 6);
  arr.insert(10, 8);
  arr.insert(11, 10);
  REQUIRE(arr.at(0) == 6);
  REQUIRE(arr.at(1) == 1);
  REQUIRE(arr.at(2) == 7);
  REQUIRE(arr.at(3) == 2);
  REQUIRE(arr.at(4) == 8);
  REQUIRE(arr.at(5) == 3);
  REQUIRE(arr.at(6) == 9);
  REQUIRE(arr.at(7) == 4);
  REQUIRE(arr.at(8) == 10);
  REQUIRE(arr.at(9) == 5);
  REQUIRE(arr.at(10) == 11);
  REQUIRE(arr.getSize() == 16);
  REQUIRE(arr.getLength() == 11);
}
