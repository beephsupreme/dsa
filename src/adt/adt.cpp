#include "adt.h"

#include <iostream>

void testes() { std::cout << "Hello from ADT!" << std::endl; }

Array::Array(int size) {
  this->size = size;
  this->A = new int[size];
  this->length = 0;
  std::cout << "Array()" << std::endl;
}

Array::~Array() {
  delete[] A;
  std::cout << "~Array()" << std::endl;
}

void Array::display() {
  std::cout << "display(): ";
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
  std::cout << "append()" << std::endl;
}

void Array::resize() {
  int* q = new int[2 * this->size];
  this->size *= 2;
  for (int i = 0; i < length; i++) {
    q[i] = this->A[i];
  }
  delete[] A;
  A = q;
  q = nullptr;
  std::cout << "resize()" << std::endl;
}

int Array::getSize() { return this->size; }

int Array::getLength() { return this->length; }

void Array::insert(int element, int index) {
  if (this->size == this->length) {
    this->resize();
  }
  int* q = new int[size];
  for (int i = 0, r = 0; i < length; i++, r++) {
    if (r == index - 1) {
      q[r] = element;
      i--;
    } else {
      q[r] = A[i];
    }
  }
  this->length++;
  delete [] A;
  A = q;
  q = nullptr;
  std::cout << "insert()" << std::endl;
}

void array_driver() {
  Array arr(3);
  std::cout << "Array size: " << arr.getSize() << std::endl;
  std::cout << "Array length: " << arr.getLength() << std::endl;
  arr.display();
  arr.append(2);
  arr.append(4);
  arr.insert(42, 2);
  arr.display();
  arr.insert(19, 2);
  arr.append(6);
  arr.display();
  arr.append(8);
  std::cout << "Array size: " << arr.getSize() << std::endl;
  std::cout << "Array length: " << arr.getLength() << std::endl;
  arr.display();
  arr.insert(13, 6);
  std::cout << "Array size: " << arr.getSize() << std::endl;
  std::cout << "Array length: " << arr.getLength() << std::endl;
  arr.display();
  arr.insert(1, 1);
  std::cout << "Array size: " << arr.getSize() << std::endl;
  std::cout << "Array length: " << arr.getLength() << std::endl;
  arr.display();
}
