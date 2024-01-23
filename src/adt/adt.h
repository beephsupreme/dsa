#pragma once

class Array {
  public:
    Array(int size);
    ~Array();
    void display();
    void insert(int element);
    int getSize();
    int getLength();

  private:
    int size;
    int length;
    int *A;
    Array(){}
    void resize();
};

void array_driver();
