#pragma once

class Array {
  public:
    Array(int size);
    ~Array();
    void display();
    void append(int element);
    int getSize();
    int getLength();
    void insert(int element, int index);

  private:
    int size;
    int length;
    int *A;
    Array(){}
    void resize();
};

void array_driver();
