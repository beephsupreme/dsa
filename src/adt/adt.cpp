#include "adt.h"
#include <iostream>
#include <stdexcept>

Array::Array() : size(8), length(0), A(new int[size]) {
}

Array::Array(int size) {
    if (size < 0) {
        throw std::out_of_range("Array::Array(size) invalid size.");
    }
    if (size < 1) {
        size = 8;
    }
    this->size = size;
    A = new(std::nothrow) int[size];
    if (!A) {
        throw std::out_of_range("Array::Array(size) failed allocation.");
    }
    length = 0;
}

Array::~Array() {
    delete[] A;
}

void Array::display() const {
    if (length == 0) {
        std::cout << "Array is empty!" << std::endl;
    } else {
        for (auto i = 0; i < length; i++) {
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
    }
}

void Array::append(const int element) {
    if (size == length) {
        this->resize();
    }
    A[length] = element;
    length++;
}

void Array::resize() {
    size *= 2;
    const auto q = new(std::nothrow) int[size];
    if (!q) {
        throw std::out_of_range("Array::resize() failed allocation.");
    }
    for (auto i = 0; i < length; i++) {
        q[i] = A[i];
    }
    delete[] A;
    A = q;
}

int Array::getSize() const {
    return size;
}

int Array::getLength() const {
    return this->length;
}

void Array::insert(const int element, const int index) {
    if ((length + 1) >= size) {
        this->resize();
    }
    const auto q = new(std::nothrow) int[size];
    if (!q) {
        throw std::out_of_range("Array::insert(element, index) failed allocation.");
    }
    for (auto i = 0, r = 0; r < length + 1; i++, r++) {
        if (r == index) {
            q[r] = element;
            i--;
        } else {
            q[r] = A[i];
        }
    }
    length++;
    delete[] A;
    A = q;
}

int Array::get(const int index) const {
    if (index < 0 || index > (length - 1)) {
        throw std::out_of_range("Array::get(index) out of range.");
    }
    return A[index];
}

void Array::set(const int element, const int index) const {
    if (index < 0 || index > (length - 1)) {
        throw std::out_of_range("Array::set(element, index) out of range.");
    }
    A[index] = element;
}

int Array::remove(const int index) {
    if (index < 0 || index > (length - 1)) {
        throw std::out_of_range("Array::remove(index) out of range.");
    }
    const int element = A[index];
    for (int i = index; i < length; i++) {
        A[i] = A[i + 1];
    }
    length--;
    return element;
}

int Array::find(const int element) const {
    for (int i = 0; i < length; i++) {
        if (A[i] == element) {
            return i;
        }
    }
    return -1;
}
