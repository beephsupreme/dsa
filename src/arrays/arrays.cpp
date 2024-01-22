#include "arrays.h"

#include <iostream>

void increase_array_size() {
  int n = 5;
  int* p = new int[n];
  for (int i = 0; i < n; i++) {
    p[i] = (i + 1) * (i + 1);
  }
  std::cout << "Array of " << n << " elements contains:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << p[i] << " ";
  }
  std::cout << std::endl;

  int* q = new int[2 * n];
  for (int i = 0; i < n; i++) {
    q[i] = p[i];
  }

  delete[] p;
  p = q;
  q = nullptr;

  std::cout << "Array of " << n << " elements contains:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << p[i] << " ";
  }
  std::cout << std::endl;

  n *= 2;
  for (int i = 5; i < n; i++) {
    p[i] = (i + 1) * (i + 1);
  }
  std::cout << "Array of " << n << " elements contains:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << p[i] << " ";
  }
  std::cout << std::endl;
}
