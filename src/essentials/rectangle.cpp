#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle(const int length, const int width) : length(length), width(width) {
  std::cout << "Rectangle created!" << std::endl;
}

Rectangle::~Rectangle() {
  std::cout << "Rectangle destroyed!" << std::endl;
}

int Rectangle::area() const {
  return length * width;
}

int Rectangle::get_length() const {
  return length;
}

int Rectangle::get_width() const {
  return width;
}

void Rectangle::set_length(const int length) {
  this->length = length;
}

void Rectangle::set_width(const int width) {
  this->width = width;
}
int Rectangle::perimeter() const {
  return 2*(length+width);
}
