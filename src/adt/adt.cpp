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
    std::cout << "Array is enpty!" << std::endl;
  } else {
    for (int i = 0; i < this->length; i++) {
      std::cout << this->A[i] << " ";
    }
    std::cout << std::endl;
  }
}

void Array::insert(int element) {
  if (this->size == this->length) {
    this->resize();
  }
  std::cout << "insert()" << std::endl;
  this->A[length] = element;
  this->length++;
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

int Array::getSize(){
  return this->size;
}

int Array::getLength() {
  return this->length;
}

void array_driver() {
  Array arr(3);
  std::cout << "Array size: " << arr.getSize() << std::endl;
  std::cout << "Array length: " << arr.getLength() << std::endl;
  arr.display();
  arr.insert(2);
  arr.insert(4);
  arr.insert(6);
  arr.display();
  arr.insert(8);
  std::cout << "Array size: " << arr.getSize() << std::endl;
  std::cout << "Array length: " << arr.getLength() << std::endl;
  arr.display();
}
