#include "adt.h"

#include <iostream>

Array::Array(int size) {
  if (size < 1) {
    size = 8;
  }
  this->size = size;
  this->A = new int[size];
  this->length = 0;
}

Array::~Array() { delete[] A; }

void Array::display() {
  if (this->length == 0) {
    std::cout << "Array is empty!" << std::endl;
  } else {
    for (int i = 0; i < this->length; i++) {
      std::cout << this->A[i] << " ";
    }
    std::cout << std::endl;
  }
}

void Array::append(int element) {
  if (this->size == this->length) {
    this->resize();
  }
  this->A[length] = element;
  this->length++;
}

void Array::resize() {
  this->size *= 2;
  int* q = new int[this->size];
  for (int i = 0; i < this->length; i++) {
    q[i] = this->A[i];
  }
  delete[] A;
  A = q;
  q = nullptr;
}

int Array::getSize() { return this->size; }

int Array::getLength() { return this->length; }

void Array::insert(int element, int index) {
  if ((this->length + 1) >= this->size) {
    this->resize();
  }
  int* q = new int[this->size];
  for (int i = 0, r = 0; r < this->length + 1; i++, r++) {
    if (r == index) {
      q[r] = element;
      i--;
    } else {
      q[r] = A[i];
    }
  }
  this->length++;
  delete[] A;
  A = q;
  q = nullptr;
}

int Array::get(int index) { return A[index]; }

void Array::set(int element, int index) { A[index] = element; }

void array_driver() {
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
  std::cout << arr.get(0) << " ";
  std::cout << arr.get(1) << " ";
  std::cout << arr.get(2) << " ";
  std::cout << arr.get(3) << " ";
  std::cout << arr.get(4) << " ";
  std::cout << arr.get(5) << " ";
  std::cout << arr.get(6) << " ";
  std::cout << arr.get(7) << " ";
  std::cout << arr.get(8) << " ";
  std::cout << arr.get(9) << " ";
  std::cout << std::endl;
  arr.set(1, 0);
  arr.set(2, 1);
  arr.set(3, 2);
  arr.set(4, 3);
  arr.set(5, 4);
  arr.set(6, 5);
  arr.set(7, 6);
  arr.set(8, 7);
  arr.set(9, 8);
  arr.set(10, 9);
  std::cout << arr.get(0) << " ";
  std::cout << arr.get(1) << " ";
  std::cout << arr.get(2) << " ";
  std::cout << arr.get(3) << " ";
  std::cout << arr.get(4) << " ";
  std::cout << arr.get(5) << " ";
  std::cout << arr.get(6) << " ";
  std::cout << arr.get(7) << " ";
  std::cout << arr.get(8) << " ";
  std::cout << arr.get(9) << " ";
  std::cout << std::endl;
}
