#include <library.h>

#include <iostream>
using namespace std;

int main() {
  cout << "\ntail recursion" << endl;
  tail_recursion(5);
  cout << endl;
  cout << "\nhead recursion" << endl;
  head_recursion(5);
  cout << endl;
  cout << "\nlinear recursion" << endl;
  linear_recursion(5);
  cout << endl;
  cout << "\ntree recursion" << endl;
  tree_recursion(5);
  cout << endl;
  return 0;
}
