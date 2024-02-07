#pragma once

#include <iostream>
#include <sstream>
#include <vector>

class HtmlBuilder;

class HtmlElement {
 private:
  std::string name, text;
  const size_t indent_size = 2;
  std::vector<HtmlElement> elements;
 public:
  friend class HtmlBuilder;
  HtmlElement() = default;
  HtmlElement(std::string name, std::string text);
  [[nodiscard]] std::string str(size_t indent = 0) const;
  static HtmlBuilder build(std::string root_name);
};
