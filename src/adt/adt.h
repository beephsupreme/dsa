#pragma once

class Array {
  public:
    Array();
    Array(int size);
    ~Array();
    void display();
    void append(int element);
    int getSize();
    int getLength();
    void insert(int element, int index);
    int get(int index);
    void set(int element,int index);
    int remove(int index);
    int find(int element);

  private:
    int size;
    int length;
    int *A;
    void resize();
};
