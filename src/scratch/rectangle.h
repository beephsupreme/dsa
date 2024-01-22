#pragma once

class Rectangle {
  private:
    int _length;
    int _width;
  public:
    Rectangle(int l, int w);
    ~Rectangle();
    int get_length();
    int get_width();
    void set_length(int l);
    void set_width(int w);
    int area();
};
