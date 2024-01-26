#pragma once

class Array {
public:
    Array();

    [[maybe_unused]] explicit Array(int size);

    ~Array();

    void display() const;

    void append(int element);

    [[nodiscard]] int getSize() const;

    [[nodiscard]] int getLength() const;

    void insert(int element, int index);

    [[nodiscard]] int get(int index) const;

    void set(int element, int index) const;

    int remove(int index);

    [[nodiscard]] int find(int element) const;

    [[nodiscard]] int min() const;

    [[nodiscard]] int max() const;

private:
    int size;
    int length;
    int *A;

    void resize();
};
