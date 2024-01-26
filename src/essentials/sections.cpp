#include "sections.h"

#include <iostream>

#include "arithmetic.h"
#include "rectangle.h"

void class_work_01() {
    std::cout << "\nclass_work_01\n";
    const Rectangle r(10, 5);
    std::cout << "Area of r = " << r.area() << std::endl;
}

void pointer_work() {
    std::cout << "\npointer_work\n";
    std::unique_ptr<int[]> p(new int[5]);
    p ? std::cout << "not empty\n" : std::cout << "empty\n";
    for (auto i = 0; i < 5; i++) {
        p[i] = 2 * (i + 1);
    }
    for (size_t i = 0; i < 5; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
    p.reset();
    p ? std::cout << "not empty\n" : std::cout << "empty\n";
    std::unique_ptr<Rectangle> r(new Rectangle(10, 5));
    std::cout << "l: " << r->get_length() << " b: " << r->get_width()
            << std::endl;
    r.reset();
}

void reference_work() {
    std::cout << "\nreference_work\n";
    int a = 5;
    int b = 6;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap_by_reference(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
}

void arrays_as_parameters() {
    std::cout << "\narrays_as_parameters\n";
    int size{0};
    std::cout << "Please enter a poistive integer: ";
    std::cin >> size;
    int *A = get_array(size);
    fill_array(A, size);
    print_array(A, size);
    delete [] A;
}

void template_classes() {
    std::cout << "\ntemplate_classes\n";
    Arithmetic<int> i(10, 5);
    std::cout << "add int: " << i.add() << " sub int: " << i.sub() << std::endl;
    Arithmetic<float> f(10.75, 5.33);
    std::cout << "add float: " << f.add() << " sub float: " << f.sub()
            << std::endl;
}

void print_hello_world() { std::cout << "\nHello World!\n"; }

void swap_by_reference(int &x, int &y) {
    const int temp = x;
    x = y;
    y = temp;
}

void print_array(const int *p, const int n) {
    for (int i = 0; i < n; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
}

int *get_array(const int n) { return new int[n]; }

void fill_array(int *p, int n) {
    for (int i = 0; i < n; i++) {
        p[i] = 3 * (i + 1);
    }
}

void rectangle_immutable(Rectangle r) {
    r.set_length(2 * r.get_length());
    r.set_width(2 * r.get_width());
    std::cout << "inside immutable: " << r.area() << std::endl;
}

void rectangle_mutable(Rectangle *r) {
    r->set_length(2 * r->get_length());
    r->set_width(2 * r->get_width());
    std::cout << "inside mutable: " << r->area() << std::endl;
}

void structures_as_parameters() {
    std::cout << "\nstructures_as_parameters\n";
    Rectangle r(12, 8);
    std::cout << "at creation: " << r.area() << std::endl;
    rectangle_immutable(r);
    std::cout << "after immutable: " << r.area() << std::endl;
    rectangle_mutable(&r);
    std::cout << "after mutable: " << r.area() << std::endl;
}
