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

Array::~Array() {
  delete[] A;
}

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
  if (this->size == this->length) {
    this->resize();
  }
  if (this->length == 0){
    this->append(element);
    return;
  }
  int* q = new int[this->size + 1];
  for (int i = 0, r = 0; i < this->length; i++, r++) {
    if (r == (index)) {
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
}

void array_driver() {

}
