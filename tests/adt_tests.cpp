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

TEST_F(AdtTest, Set) {
  for (auto i{0}; i < 10; i++) {
    arr_increasing.set(2 * (i + 1), i);
  }
  for (auto i{0}; i < 10; i++) {
    EXPECT_EQ(arr_increasing.get(i), 2 * (i + 1));
  }
}

TEST_F(AdtTest, ConstructToSize) {
  Array arr(1E6);
  for (auto i{0}; i < 5E5; i++) {
    arr.append(i);
  }
  EXPECT_EQ(arr.getLength(), 5E5);
  EXPECT_EQ(arr.getSize(), 1E6);
}

TEST_F(AdtTest, CopyConstructor) {
  Array arr_i(arr_increasing);
  Array arr_d(arr_decreasing);
  Array arr_r(arr_random);
  arr_increasing.append(42);
  arr_decreasing.append(42);
  arr_random.append(42);
  EXPECT_EQ(arr_i.getSize(), 16);
  EXPECT_EQ(arr_d.getSize(), 16);
  EXPECT_EQ(arr_r.getSize(), 16);
  EXPECT_EQ(arr_i.getLength(), 10);
  EXPECT_EQ(arr_d.getLength(), 10);
  EXPECT_EQ(arr_r.getLength(), 10);
  for (auto i{0}; i < 10; i++) {
    EXPECT_EQ(arr_i.get(i), i + 1);
  }
  for (auto i{0}; i < 10; i++) {
    EXPECT_EQ(arr_d.get(i), 10 - i);
  }
  ASSERT_EQ(arr_r.get(0), 8);
  ASSERT_EQ(arr_r.get(1), 2);
  ASSERT_EQ(arr_r.get(2), 7);
  ASSERT_EQ(arr_r.get(3), 1);
  ASSERT_EQ(arr_r.get(4), 3);
  ASSERT_EQ(arr_r.get(5), 4);
  ASSERT_EQ(arr_r.get(6), 5);
  ASSERT_EQ(arr_r.get(7), 9);
  ASSERT_EQ(arr_r.get(8), 6);
  ASSERT_EQ(arr_r.get(9), 10);
}

TEST_F(AdtTest, InsertFirst) {
  arr_increasing.insert(42, 0);
  ASSERT_EQ(arr_increasing.getLength(), 11);
  ASSERT_EQ(arr_increasing.get(0), 42);
  for (auto i{1}; i < 11; i++) {
    ASSERT_EQ(arr_increasing.get(i), i);
  }
}

TEST_F(AdtTest, RemoveFirst) {
  arr_increasing.remove(0);
  ASSERT_EQ(arr_increasing.getLength(), 9);
  for (auto i{0}; i < 9; i++) {
    ASSERT_EQ(arr_increasing.get(i), i + 2);
  }
}

TEST_F(AdtTest, InsertLast) {
  arr_increasing.insert(42, 10);
  ASSERT_EQ(arr_increasing.getLength(), 11);
  for (auto i{0}; i < 10; i++) {
    ASSERT_EQ(arr_increasing.get(i), i + 1);
  }
  ASSERT_EQ(arr_increasing.get(10), 42);
}

TEST_F(AdtTest, RemoveLast) {
  arr_increasing.remove(9);
  ASSERT_EQ(arr_increasing.getLength(), 9);
  for (auto i{0}; i < 9; i++) {
    ASSERT_EQ(arr_increasing.get(i), i + 1);
  }
}

TEST_F(AdtTest, InsertMid) {
  arr_increasing.insert(42, 5);
  EXPECT_EQ(arr_increasing.getLength(), 11);
  for (auto i{0}, j{1}; i < 10; i++, j++) {
    if (i == 5) {
      j--;
      continue;
    }
    ASSERT_EQ(arr_increasing.get(i), j);
  }
  ASSERT_EQ(arr_increasing.get(5), 42);
}

TEST_F(AdtTest, RemoveMid) {
  arr_increasing.remove(5);
  EXPECT_EQ(arr_increasing.getLength(), 9);
  for (auto i{0}, j{1}; i < 8; i++, j++) {
    if (i == 5) j++;
    ASSERT_EQ(arr_increasing.get(i), j);
  }
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

TEST_F(AdtTest, Sort) {
  arr_increasing.sort();
  arr_decreasing.sort();
  arr_random.sort();
  for (auto i{0}; i < 10; i++) {
    EXPECT_EQ(arr_increasing.get(i), i + 1);
    EXPECT_EQ(arr_decreasing.get(i), i + 1);
    EXPECT_EQ(arr_random.get(i), i + 1);
  }
}

TEST_F(AdtTest, isSorted) {
  ASSERT_EQ(arr_increasing.isSorted(), true);
  ASSERT_EQ(arr_decreasing.isSorted(), false);
  ASSERT_EQ(arr_random.isSorted(), false);
  arr_decreasing.sort();
  arr_random.sort();
  ASSERT_EQ(arr_decreasing.isSorted(), true);
  ASSERT_EQ(arr_random.isSorted(), true);
}

TEST_F(AdtTest, FindSorted) {
  for (auto i{0}; i < 10; i++) {
    ASSERT_EQ(arr_increasing.find(i + 1), i);
  }
  ASSERT_EQ(arr_increasing.find(11), -1);
}

TEST_F(AdtTest, FindUnSorted) {
  ASSERT_EQ(arr_random.find(8), 0);
  ASSERT_EQ(arr_random.find(2), 1);
  ASSERT_EQ(arr_random.find(7), 2);
  ASSERT_EQ(arr_random.find(1), 3);
  ASSERT_EQ(arr_random.find(3), 4);
  ASSERT_EQ(arr_random.find(4), 5);
  ASSERT_EQ(arr_random.find(5), 6);
  ASSERT_EQ(arr_random.find(9), 7);
  ASSERT_EQ(arr_random.find(6), 8);
  ASSERT_EQ(arr_random.find(10), 9);
  ASSERT_EQ(arr_increasing.find(11), -1);
}

TEST_F(AdtTest, Reverse) {
  arr_decreasing.reverse();
  for (auto i{0}; i < 10; i++) {
    EXPECT_EQ(arr_increasing.get(i), arr_decreasing.get(i));
  }
}

