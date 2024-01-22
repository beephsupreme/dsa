#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle(int l, int w){
  _length = l;
  _width = w;
  std::cout << "Rectangle created!" << std::endl;
}

Rectangle::~Rectangle() {
  std::cout << "Rectangle destroyed!" << std::endl;
}

int Rectangle::area() {
  return _length * _width;
}

int Rectangle::get_length() {
  return _length;
}

int Rectangle::get_width(){
  return _width;
}

void Rectangle::set_length(int l) {
  _length = l;
}

void Rectangle::set_width(int w) {
  _width = w;
}
