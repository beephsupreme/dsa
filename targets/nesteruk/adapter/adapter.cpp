#include <bits/stdc++.h>
#include <boost/lexical_cast.hpp>
#include <gtest/gtest.h>

using namespace std;

TEST(AdapterTests, BasicTests) {
  cout << "Ready To Test!" << endl;
}

int main(int ac, char *av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
