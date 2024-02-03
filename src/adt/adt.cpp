#include "adt.h"
#include <iostream>
#include <stdexcept>

Array::Array() : size(8), length(0), A(new int[size]) {
}

Array::Array(int32_t size) {
  try {
    if (size < 0) {
      throw std::out_of_range("size < 0");
    }
    if (size < 1) {
      size = 8;
    }
    this->size = size;
    A = new int32_t[size];
    length = 0;
  } catch (std::bad_alloc &) {
    std::cerr << "Array::Array(size) could not allocate heap memory to create array" << std::endl;
    throw;
  } catch (std::out_of_range &) {
    std::cerr << "Array::Array(size) size cannot be less than 0" << std::endl;
    throw;
  }
}

Array::Array(Array &arr) {
  size = arr.size;
  length = arr.length;
  if (size < 0) {
    throw std::out_of_range("Array::Array(size) invalid size.");
  }
  if (size < 1) {
    size = 8;
  }
  A = new(std::nothrow) int32_t[size];
  if (!A) {
    throw std::out_of_range("Array::Array(size) failed allocation.");
  }
  for (auto i{0}; i < length; i++) {
    A[i] = arr.A[i];
  }
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

void Array::append(const int32_t element) {
  if (size == length) {
    this->resize();
  }
  A[length] = element;
  length++;
}

void Array::resize() {
  size *= 2;
  const auto q = new(std::nothrow) int32_t[size];
  if (!q) {
    throw std::out_of_range("Array::resize() failed allocation.");
  }
  for (auto i = 0; i < length; i++) {
    q[i] = A[i];
  }
  delete[] A;
  A = q;
}

int32_t Array::getSize() const noexcept {
  return size;
}

int32_t Array::getLength() const noexcept {
  return this->length;
}

void Array::insert(const int32_t element, const int32_t index) {
  if ((length + 1) >= size) {
    this->resize();
  }
  const auto q = new(std::nothrow) int32_t[size];
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

int32_t Array::get(const int32_t index) const {
  if (index < 0 || index > (length - 1)) {
    throw std::out_of_range("Array::get(index) out of range.");
  }
  return A[index];
}

void Array::set(int32_t element, int32_t index) {
  if (index < 0 || index > (length - 1)) {
    throw std::out_of_range("Array::set(element, index) out of range.");
  }
  A[index] = element;
}

int32_t Array::remove(const int32_t index) {
  if (index < 0 || index > (length - 1)) {
    throw std::out_of_range("Array::remove(index) out of range.");
  }
  const int32_t element = A[index];
  for (auto i{index}; i < length; i++) {
    A[i] = A[i + 1];
  }
  length--;
  return element;
}

int32_t Array::min() const {
  auto x = A[0];
  for (auto i{0}; i < length; i++) {
    if (A[i] < x) {
      x = A[i];
    }
  }
  return x;
}

int32_t Array::max() const {
  auto x = A[0];
  for (auto i{0}; i < length; i++) {
    if (A[i] > x) {
      x = A[i];
    }
  }
  return x;
}

void Array::reverse() {
  try {
    const auto q = new int32_t[size];
    for (auto i{0}, j{length - 1}; i < length; i++, j--) {
      q[i] = A[j];
    }
    delete[] A;
    A = q;
  } catch (std::bad_alloc &) {
    std::cerr << "Array::reverse() could not allocate heap memory to reverse array" << std::endl;
    throw;
  }
}

int32_t Array::sum() {
  auto sum{0};
  for (auto i{0}; i < length; i++) {
    sum += A[i];
  }
  return sum;
}
double Array::avg() {
  if (length == 0) {
    throw std::out_of_range("Array::avg() 0-length array has no average.");
  }
  auto s = static_cast<double>(sum());
  return s / static_cast<double>(length);
}

void Array::sort() {
  for (int32_t i{0}; i < length; i++) {
    int32_t min = i;
    for (int32_t j{i + 1}; j < length; j++) {
      if (A[j] < A[min]) {
        min = j;
      }
    }
    if (min != i) {
      int32_t temp{A[i]};
      A[i] = A[min];
      A[min] = temp;
    }
  }
}

bool Array::isSorted() {
  for (auto i{0}; i < length - 1; i++) {
    if (A[i] > A[i + 1]) {
      return false;
    }
  }
  return true;
}

int32_t Array::linear_search(int32_t element) {
  for (int32_t i{0}; i < length; i++) {
    if (A[i] == element) {
      return i;
    }
  }
  return -1;
}

int32_t Array::binary_search(int32_t element) {
  int32_t l{0}, h{length - 1}, mid;
  while (l <= h) {
    mid = (l + h) / 2;
    if (element == A[mid]) {
      return mid;
    } else if (element < A[mid]) {
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return -1;
}

int32_t Array::find(int32_t element) {
  if (isSorted()) {
    return this->binary_search(element);
  } else {
    return this->linear_search(element);
  }
}
