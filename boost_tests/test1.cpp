#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "../src/adt/adt.h"
#include <iostream>

BOOST_AUTO_TEST_SUITE(adt)

BOOST_AUTO_TEST_CASE(get) {

  Array arr;
  for (auto i{1}; i < 11; i++) {
    arr.append(i);
  }
  for (auto i{0}; i < 10; i++) {
    BOOST_CHECK_EQUAL(arr.get(i), i + 1);
  }
  BOOST_CHECK_EQUAL(arr.getSize(),16);
  BOOST_CHECK_EQUAL(arr.getLength(),10);
}

BOOST_AUTO_TEST_CASE(append) {

  Array arr;
  for (auto i{1}; i < 11; i++) {
    arr.append(i);
  }
  for (auto i{0}; i < 10; i++) {
    BOOST_CHECK_EQUAL(arr.get(i), i + 1);
  }
}
}