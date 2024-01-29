#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "adt.h"

TEST_CASE("ADT Array Get/Append", "[get-append]") {
  Array arr;
  for (auto i{1}; i < 11; i++) {
    arr.append(i);
  }
  for (auto i{0}; i < 10; i++) {
    REQUIRE(arr.get(i) == i + 1);
  }
  REQUIRE(arr.getSize() == 16);
  REQUIRE(arr.getLength() == 10);
}

TEST_CASE("ADT Array Insert @ Back", "[insert-back]") {
  Array arr(16);
  for (auto i = 0; i < 10; i++) {
    arr.insert(i + 1, i);
  }
  for (auto i{0}; i < 10; i++) {
    REQUIRE(arr.get(i) == i + 1);
  }
  REQUIRE(arr.getSize() == 16);
  REQUIRE(arr.getLength() == 10);
}

TEST_CASE("ADT Array Insert @ Front", "[insert-front]") {
  Array arr;
  for (auto i{1}; i < 11; i++) {
    arr.insert(i, 0);
  }
  for (auto i{0}, j{10}; i < 10; i++, j--) {
    REQUIRE(arr.get(i) == j);
  }
  REQUIRE(arr.getSize() == 16);
  REQUIRE(arr.getLength() == 10);
}

TEST_CASE("ADT Array Insert @ Will", "[insert-will]") {
  Array arr;
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
  REQUIRE(arr.get(0) == 6);
  REQUIRE(arr.get(1) == 1);
  REQUIRE(arr.get(2) == 7);
  REQUIRE(arr.get(3) == 2);
  REQUIRE(arr.get(4) == 8);
  REQUIRE(arr.get(5) == 3);
  REQUIRE(arr.get(6) == 9);
  REQUIRE(arr.get(7) == 4);
  REQUIRE(arr.get(8) == 10);
  REQUIRE(arr.get(9) == 5);
  REQUIRE(arr.get(10) == 11);
  REQUIRE(arr.getSize() == 16);
  REQUIRE(arr.getLength() == 11);
}

TEST_CASE("ADT Array Set", "[set]") {
  Array arr;
  for (auto i = 0; i < 10; i++) {
    arr.append(i);
  }
  for (auto i = 0; i < 10; i++) {
    arr.set(2 * (i + 1), i);
  }
  for (auto i{0}; i < 10; i++) {
    REQUIRE(arr.get(i) == 2 * (i + 1));
  }
}

TEST_CASE("ADT Array Remove", "[remove]") {
  Array arr;
  arr.append(1);
  arr.remove(0);
  REQUIRE(arr.getLength() == 0);
  for (auto i = 1; i < 11; i++) {
    arr.append(i);
  }
  REQUIRE(arr.remove(0) == 1);
  REQUIRE(arr.remove(1) == 3);
  REQUIRE(arr.remove(2) == 5);
  REQUIRE(arr.remove(3) == 7);
  REQUIRE(arr.remove(4) == 9);
  REQUIRE(arr.remove(4) == 10);
  REQUIRE(arr.get(0) == 2);
  REQUIRE(arr.get(1) == 4);
  REQUIRE(arr.get(2) == 6);
  REQUIRE(arr.get(3) == 8);
}

TEST_CASE("ADT Array Find", "[find]") {
  Array arr;
  arr.append(8);
  arr.append(2);
  arr.append(7);
  arr.append(1);
  arr.append(3);
  arr.append(4);
  arr.append(5);
  arr.append(9);
  arr.append(6);
  arr.append(10);
  REQUIRE(arr.find(8) == 0);
  REQUIRE(arr.find(1) == 3);
  REQUIRE(arr.find(10) == 9);
  REQUIRE(arr.find(11) == -1);
  arr.sort();
  for (auto i{0}; i < 10; i++) {
    REQUIRE(arr.find(i + 1) == i);
  }
  REQUIRE(arr.find(11) == -1);
}

TEST_CASE("ADT Array Reverse", "[reverse]") {
  Array arr;
  for (auto i{0}; i < 10; i++) {
    arr.append(i);
  }
  for (auto i{0}; i < 10; i++) {
    REQUIRE(arr.get(i) == i);
  }
  arr.reverse();
  for (auto i{0}, j{9}; i < 10; i++, j--) {
    REQUIRE(arr.get(i) == j);
  }
  arr.remove(9);
  for (auto i{0}, j{9}; i < 9; i++, j--) {
    REQUIRE(arr.get(i) == j);
  }
  arr.reverse();
  for (auto i{0}; i < 9; i++) {
    REQUIRE(arr.get(i) == i + 1);
  }
}

TEST_CASE("ADT Array Sum", "[sum]") {
  Array arr;
  for (auto i{1}; i < 11; i++) {
    arr.append(i);
  }
  REQUIRE(arr.sum() == 55);
}

TEST_CASE("ADT Array Avg", "[avg]") {
  Array arr;
  for (auto i{1}; i < 11; i++) {
    arr.append(i);
  }
  REQUIRE(arr.avg() == 5.5);
}

TEST_CASE("ADT Array Sort", "[sort]") {
  Array arr;
  for (auto i{9}; i >= 0; i--) {
    arr.append(i);
  }
  arr.sort();
  for (auto i{0}; i < 10; i++) {
    REQUIRE(arr.get(i) == i);
  }
}

TEST_CASE("ADT Array Copy Constructor", "[copy]") {
  Array arr;
  arr.append(8);
  arr.append(2);
  arr.append(7);
  arr.append(1);
  arr.append(3);
  arr.append(4);
  arr.append(5);
  arr.append(9);
  arr.append(6);
  arr.append(10);
  Array copy(arr);
  arr.reverse();
  REQUIRE(copy.find(8) == 0);
  REQUIRE(copy.find(2) == 1);
  REQUIRE(copy.find(7) == 2);
  REQUIRE(copy.find(1) == 3);
  REQUIRE(copy.find(3) == 4);
  REQUIRE(copy.find(4) == 5);
  REQUIRE(copy.find(5) == 6);
  REQUIRE(copy.find(9) == 7);
  REQUIRE(copy.find(6) == 8);
  REQUIRE(copy.find(10) == 9);
}
