#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle(const int length, const int width) : length(length), width(width){


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

int Rectangle::get_width() const{
  return width;
}

void Rectangle::set_length(int l) {
  length = l;
}

void Rectangle::set_width(int w) {
  width = w;
}
