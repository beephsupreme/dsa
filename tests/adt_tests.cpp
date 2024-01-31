#include <adt.h>
#include <gtest/gtest.h>


class AdtTest : public testing::Test {
 protected:
  Array arr_increasing;
  Array arr_decreasing;
  Array arr_random;
  void SetUp() override {
    for (auto i{1}; i < 11; i++) {
      arr_increasing.append(i);
    }
    for (auto i{10}; i > 0; i--) {
      arr_decreasing.append(i);
    }
    arr_random.append(8);  // 0
    arr_random.append(2);  // 1
    arr_random.append(7);  // 2
    arr_random.append(1);  // 3
    arr_random.append(3);  // 4
    arr_random.append(4);  // 5
    arr_random.append(5);  // 6
    arr_random.append(9);  // 7
    arr_random.append(6);  // 8
    arr_random.append(10); // 9
  }
};

TEST_F(AdtTest, RemoveLast) {
  arr_increasing.remove(9);
  EXPECT_EQ(arr_increasing.getLength(), 9);
  ASSERT_EQ(arr_increasing.get(0), 1);
  ASSERT_EQ(arr_increasing.get(8), 9);
}

TEST_F(AdtTest, GetInitialSize) {
  EXPECT_EQ(arr_increasing.getSize(), 16);
  EXPECT_EQ(arr_decreasing.getSize(), 16);
  EXPECT_EQ(arr_random.getSize(), 16);
}

TEST_F(AdtTest, GetInitalLength) {
  EXPECT_EQ(arr_increasing.getLength(), 10);
  EXPECT_EQ(arr_decreasing.getLength(), 10);
  EXPECT_EQ(arr_random.getLength(), 10);
}

TEST_F(AdtTest, CheckInitalValues) {
  for (auto i{0}; i < 10; i++) {
    EXPECT_EQ(arr_increasing.get(i), i + 1);
  }
  for (auto i{0}; i < 10; i++) {
    EXPECT_EQ(arr_decreasing.get(i), 10 - i);
  }
  ASSERT_EQ(arr_random.get(0), 8);
  ASSERT_EQ(arr_random.get(1), 2);
  ASSERT_EQ(arr_random.get(2), 7);
  ASSERT_EQ(arr_random.get(3), 1);
  ASSERT_EQ(arr_random.get(4), 3);
  ASSERT_EQ(arr_random.get(5), 4);
  ASSERT_EQ(arr_random.get(6), 5);
  ASSERT_EQ(arr_random.get(7), 9);
  ASSERT_EQ(arr_random.get(8), 6);
  ASSERT_EQ(arr_random.get(9), 10);
}
