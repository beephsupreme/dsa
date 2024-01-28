#pragma once

class Array {
 public:
  Array();
  explicit Array(int size);
  ~Array();
  void display() const;
  void append(int element);
  [[nodiscard]] int getSize() const;
  [[nodiscard]] int getLength() const;
  void insert(int element, int index);
  [[nodiscard]] int get(int index) const;
  void set(int element, int index);
  int remove(int index);
  [[nodiscard]] int find(int element);
  [[nodiscard]] int min() const;
  [[nodiscard]] int max() const;
  void reverse();
  int sum();
  double avg();
  void sort();
 private:
  int size;
  int length;
  int *A;
  void resize();
  bool sorted;
  int linear_search(int element);
  int binary_search(int element);
};
