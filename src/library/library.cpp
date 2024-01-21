#include "library.h"

#include <iostream>

void testes() { std::cout << "Hello World!\n"; }

void tail_recursion(int n) {
  if (n > 0) {
    std::cout << n << " ";
    tail_recursion(n - 1);
  }
}

void head_recursion(int n) {
  if (n > 0) {
    head_recursion(n - 1);
    std::cout << n << " ";
  }
}

void linear_recursion(int n) {
  if (n > 0) {
    std::cout << n << " ";
    linear_recursion(n - 1);
    std::cout << n << " ";
  }
}

void tree_recursion(int n) {
  if (n > 0) {
    std::cout << n << " ";
    tree_recursion(n - 1);
    tree_recursion(n - 1);
  }
}