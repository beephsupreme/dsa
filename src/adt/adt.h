#pragma once

class Array {
  public:
    int size;
    int length;

    Array(int size);
    ~Array();
    void display();
    void insert(int element);

  private:
    int *A;
    Array(){}
    void resize();
};

void array_driver();
