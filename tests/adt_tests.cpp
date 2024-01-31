#include <gtest/gtest.h>
#include <adt.h>

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

TEST_F(AdtTest, Append) {
  arr_increasing.append(11);
  EXPECT_EQ(arr_increasing.get(10), 11);
}

TEST_F(AdtTest, InsertFirst) {
  arr_increasing.insert(42, 0);
  ASSERT_EQ(arr_increasing.getLength(), 11);
  ASSERT_EQ(arr_increasing.get(0), 42);
  ASSERT_EQ(arr_increasing.get(1), 1);
  ASSERT_EQ(arr_increasing.get(2), 2);
  ASSERT_EQ(arr_increasing.get(3), 3);
  ASSERT_EQ(arr_increasing.get(4), 4);
  ASSERT_EQ(arr_increasing.get(5), 5);
  ASSERT_EQ(arr_increasing.get(6), 6);
  ASSERT_EQ(arr_increasing.get(7), 7);
  ASSERT_EQ(arr_increasing.get(8), 8);
  ASSERT_EQ(arr_increasing.get(9), 9);
  ASSERT_EQ(arr_increasing.get(10), 10);
}

TEST_F(AdtTest, RemoveFirst) {
  arr_increasing.remove(0);
  ASSERT_EQ(arr_increasing.getLength(), 9);
  ASSERT_EQ(arr_increasing.get(0), 2);
  ASSERT_EQ(arr_increasing.get(1), 3);
  ASSERT_EQ(arr_increasing.get(2), 4);
  ASSERT_EQ(arr_increasing.get(3), 5);
  ASSERT_EQ(arr_increasing.get(4), 6);
  ASSERT_EQ(arr_increasing.get(5), 7);
  ASSERT_EQ(arr_increasing.get(6), 8);
  ASSERT_EQ(arr_increasing.get(7), 9);
  ASSERT_EQ(arr_increasing.get(8), 10);
}

TEST_F(AdtTest, InsertLast) {
  arr_increasing.insert(42, 10);
  ASSERT_EQ(arr_increasing.getLength(), 11);
  ASSERT_EQ(arr_increasing.get(0), 1);
  ASSERT_EQ(arr_increasing.get(1), 2);
  ASSERT_EQ(arr_increasing.get(2), 3);
  ASSERT_EQ(arr_increasing.get(3), 4);
  ASSERT_EQ(arr_increasing.get(4), 5);
  ASSERT_EQ(arr_increasing.get(5), 6);
  ASSERT_EQ(arr_increasing.get(6), 7);
  ASSERT_EQ(arr_increasing.get(7), 8);
  ASSERT_EQ(arr_increasing.get(8), 9);
  ASSERT_EQ(arr_increasing.get(9), 10);
  ASSERT_EQ(arr_increasing.get(10), 42);
}

TEST_F(AdtTest, RemoveLast) {
  arr_increasing.remove(9);
  ASSERT_EQ(arr_increasing.getLength(), 9);
  ASSERT_EQ(arr_increasing.get(0), 1);
  ASSERT_EQ(arr_increasing.get(1), 2);
  ASSERT_EQ(arr_increasing.get(2), 3);
  ASSERT_EQ(arr_increasing.get(3), 4);
  ASSERT_EQ(arr_increasing.get(4), 5);
  ASSERT_EQ(arr_increasing.get(5), 6);
  ASSERT_EQ(arr_increasing.get(6), 7);
  ASSERT_EQ(arr_increasing.get(7), 8);
  ASSERT_EQ(arr_increasing.get(8), 9);
}

TEST_F(AdtTest, InsertMid) {
  arr_increasing.insert(42, 5);
  EXPECT_EQ(arr_increasing.getLength(), 11);
  ASSERT_EQ(arr_increasing.get(0), 1);
  ASSERT_EQ(arr_increasing.get(1), 2);
  ASSERT_EQ(arr_increasing.get(2), 3);
  ASSERT_EQ(arr_increasing.get(3), 4);
  ASSERT_EQ(arr_increasing.get(4), 5);
  ASSERT_EQ(arr_increasing.get(5), 42);
  ASSERT_EQ(arr_increasing.get(6), 6);
  ASSERT_EQ(arr_increasing.get(7), 7);
  ASSERT_EQ(arr_increasing.get(8), 8);
  ASSERT_EQ(arr_increasing.get(9), 9);
  ASSERT_EQ(arr_increasing.get(10), 10);
}

TEST_F(AdtTest, RemoveMid) {
  arr_increasing.remove(5);
  EXPECT_EQ(arr_increasing.getLength(), 9);
  ASSERT_EQ(arr_increasing.get(0), 1);
  ASSERT_EQ(arr_increasing.get(1), 2);
  ASSERT_EQ(arr_increasing.get(2), 3);
  ASSERT_EQ(arr_increasing.get(3), 4);
  ASSERT_EQ(arr_increasing.get(4), 5);
  ASSERT_EQ(arr_increasing.get(5), 7);
  ASSERT_EQ(arr_increasing.get(6), 8);
  ASSERT_EQ(arr_increasing.get(7), 9);
  ASSERT_EQ(arr_increasing.get(8), 10);
}

TEST_F(AdtTest, Min) {
  EXPECT_EQ(arr_increasing.min(), 1);
  arr_increasing.append(-42);
  EXPECT_EQ(arr_increasing.min(), -42);
}

TEST_F(AdtTest, Max) {
  EXPECT_EQ(arr_increasing.max(), 10);
  arr_increasing.append(42);
  EXPECT_EQ(arr_increasing.max(), 42);
}

TEST_F(AdtTest, Sum) {
  EXPECT_EQ(arr_increasing.sum(), 55);
  arr_increasing.append(11);
  EXPECT_EQ(arr_increasing.sum(), 66);
}

TEST_F(AdtTest, Avg) {
  EXPECT_EQ(arr_increasing.avg(), 5.5);
  arr_increasing.append(11);
  EXPECT_EQ(arr_increasing.avg(), 6.0);
}
