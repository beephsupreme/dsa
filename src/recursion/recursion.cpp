#include "recursion.h"

#include <iostream>

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

void indirect_recursion(int n) {
  indirect_a(n);
  std::cout << std::endl;
}

void indirect_a(int n) {
  if (n > 0) {
    std::cout << n << " ";
    indirect_b(n - 1);
  }
}

void indirect_b(int n) {
  if (n > 1) {
    std::cout << n << " ";
    indirect_a(n / 2);
  }
}

void nested_recursion(int n) { std::cout << nested_fun(n) << std::endl; }

int nested_fun(int n) {
  if (n > 100) {
    return n - 10;
  }
  return nested_fun(nested_fun(n + 11));
}

int sum_of_n(int n) {
  if (n == 0) {
    return 0;
  }
  return sum_of_n(n - 1) + n;
}
int factorial(int n) {
  if (n < 2) {
    return 1;
  }
  return factorial(n - 1) * n;
}

int power(int m, int n) {
  if (n == 0) {
    return 1;
  }
  return power(m, n - 1) * m;
}
double taylor(int x, int n) {
  static double p{1.0}, f{1.0};
  if (n == 0) {
    return 1;
  }
  double r = taylor(x, n - 1);
  p *= x;
  f *= n;
  return r + p / f;
}

double horner(int x, int n) {
  static double s{1.0};
  if (n == 0) {
    return s;
  }
  s = 1 + x * s / n;
  return horner(x, n - 1);
}

int fibonacci(int n) {
  static int MEMO[100];
  static bool m = false;

  if (!m) {
    for (int i = 0; i < 100; i++) {
      MEMO[i] = -1;
    }
    m = true;
  }

  if (n < 2) {
    MEMO[n] = n;
    return n;
  } else {
    if (MEMO[n - 2] == -1) {
      MEMO[n - 2] = fibonacci(n - 2);
    }
    if (MEMO[n - 1] == -1) {
      MEMO[n - 1] = fibonacci(n - 1);
    }
    return MEMO[n - 2] + MEMO[n - 1];
  }
}
