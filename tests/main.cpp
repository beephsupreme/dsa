#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "adt.h"

TEST_CASE("ADT Array Get/Append", "[get-append]") {
    Array arr;
    for (auto i = 1; i < 11; i++) {
        arr.append(i);
    }
    REQUIRE(arr.get(0) == 1);
    REQUIRE(arr.get(1) == 2);
    REQUIRE(arr.get(2) == 3);
    REQUIRE(arr.get(3) == 4);
    REQUIRE(arr.get(4) == 5);
    REQUIRE(arr.get(5) == 6);
    REQUIRE(arr.get(6) == 7);
    REQUIRE(arr.get(7) == 8);
    REQUIRE(arr.get(8) == 9);
    REQUIRE(arr.get(9) == 10);
    REQUIRE(arr.getSize() == 16);
    REQUIRE(arr.getLength() == 10);
}

TEST_CASE("ADT Array Insert @ Back", "[insert-back]") {
    Array arr;
    for (auto i = 0; i < 10; i++) {
        arr.insert(i + 1, i);
    }
    REQUIRE(arr.get(0) == 1);
    REQUIRE(arr.get(1) == 2);
    REQUIRE(arr.get(2) == 3);
    REQUIRE(arr.get(3) == 4);
    REQUIRE(arr.get(4) == 5);
    REQUIRE(arr.get(5) == 6);
    REQUIRE(arr.get(6) == 7);
    REQUIRE(arr.get(7) == 8);
    REQUIRE(arr.get(8) == 9);
    REQUIRE(arr.get(9) == 10);
    REQUIRE(arr.getSize() == 16);
    REQUIRE(arr.getLength() == 10);
}

TEST_CASE("ADT Array Insert @ Front", "[insert-front]") {
    Array arr;
    for (int i = 1; i < 11; i++) {
        arr.insert(i, 0);
    }
    REQUIRE(arr.get(0) == 10);
    REQUIRE(arr.get(1) == 9);
    REQUIRE(arr.get(2) == 8);
    REQUIRE(arr.get(3) == 7);
    REQUIRE(arr.get(4) == 6);
    REQUIRE(arr.get(5) == 5);
    REQUIRE(arr.get(6) == 4);
    REQUIRE(arr.get(7) == 3);
    REQUIRE(arr.get(8) == 2);
    REQUIRE(arr.get(9) == 1);
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
    REQUIRE(arr.get(0) == 2);
    REQUIRE(arr.get(1) == 4);
    REQUIRE(arr.get(2) == 6);
    REQUIRE(arr.get(3) == 8);
    REQUIRE(arr.get(4) == 10);
    REQUIRE(arr.get(5) == 12);
    REQUIRE(arr.get(6) == 14);
    REQUIRE(arr.get(7) == 16);
    REQUIRE(arr.get(8) == 18);
    REQUIRE(arr.get(9) == 20);
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
    for (auto i = 1; i < 11; i++) {
        arr.append(i);
    }
    arr.display();
    REQUIRE(arr.find(1) == 0);
    REQUIRE(arr.find(2) == 1);
    REQUIRE(arr.find(3) == 2);
    REQUIRE(arr.find(4) == 3);
    REQUIRE(arr.find(5) == 4);
    REQUIRE(arr.find(6) == 5);
    REQUIRE(arr.find(7) == 6);
    REQUIRE(arr.find(8) == 7);
    REQUIRE(arr.find(9) == 8);
    REQUIRE(arr.find(10) == 9);
    REQUIRE(arr.find(11) == -1);
}
