#include "sections.h"
#include "arithmetic.h"

#include <iostream>

void template_classes() {
  std::cout << "\ntemplate_classes\n";
  Arithmetic<int> i(10, 5);
  std::cout << "add int: " << i.add() << " sub int: " << i.sub() << std::endl;
  Arithmetic<float> f(10.75, 5.33);
  std::cout << "add float: " << f.add() << " sub float: " << f.sub() << std::endl;
}
