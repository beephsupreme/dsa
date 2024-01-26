#include "adt.h"
#include <iostream>
#include <stdexcept>

Array::Array() : size(8), length(0), A(new int[this->size]) {
}

Array::Array(int size) {
    if (size < 0) {
        throw std::out_of_range("Array::Array(size) invalid size.");
    }
    if (size < 1) {
        size = 8;
    }
    this->size = size;
    this->A = new(std::nothrow) int[size];
    if (!A) {
        std::cerr << "Array::Array(size) bad memory allocation." << std::endl;
        throw size;
    }
    this->length = 0;
}

Array::~Array() {
    delete[] A;
}

void Array::display() const {
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
    int *q = new int[this->size];
    for (int i = 0; i < this->length; i++) {
        q[i] = this->A[i];
    }
    delete[] A;
    A = q;
    q = nullptr;
}

int Array::getSize() const {
    return this->size;
}

int Array::getLength() const {
    return this->length;
}

void Array::insert(const int element, const int index) {
    if ((this->length + 1) >= this->size) {
        this->resize();
    }
    int *q = new int[this->size];
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

int Array::get(int index) const {
    if (index < 0 || index > (this->length - 1)) {
        std::cerr << "Array::get(index) out of range." << std::endl;
        throw index;
    }
    return A[index];
}

void Array::set(const int element, const int index) const {
    A[index] = element;
}

int Array::remove(const int index) {
    const int element = A[index];
    for (int i = index; i < this->length; i++) {
        A[i] = A[i + 1];
    }
    length--;
    return element;
}

int Array::find(const int element) {
    for (int i = 0; i < this->length; i++) {
        if (A[i] == element) {
            return i;
        }
    }
    return -1;
}
