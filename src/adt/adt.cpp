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

int Array::remove(int index) {
  int element = A[index];
  for (int i = index + 1; i < this->length; i++) {
    A[i - 1] = A[i];
  }
  length--;
  return element;
}

int Array::find(int element) {
  for (size_t i = 0; i < this->length; i++) {
    if (A[i] == element) {
      return i;
    }
  }
  return -1;
}
