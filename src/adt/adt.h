#pragma once

class Array {
  public:
    Array();
    explicit Array(int size);
    ~Array();
    void display() const;
    void append(int element);
    [[nodiscard]] int getSize() const;
    [[nodiscard]] int getLength() const;
    void insert(int element, int index);
    [[nodiscard]] int get(int index) const;
    void set(int element,int index) const;
    int remove(int index);
    int find(int element);

  private:
    int size;
    int length;
    int *A;
    void resize();
};
