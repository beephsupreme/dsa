#pragma once

class Rectangle {
  private:
    int length;
    int width;
  public:
    Rectangle(int length, int width);
    ~Rectangle();
    [[nodiscard]] int get_length() const;
    [[nodiscard]] int get_width() const;
    void set_length(int length);
    void set_width(int width);
    [[nodiscard]] int area() const;
};
