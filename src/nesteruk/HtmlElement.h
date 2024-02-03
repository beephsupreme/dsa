#pragma once

#include <iostream>
#include <sstream>

struct HtmlBuilder;

struct HtmlElement {
    std::string name, text;
    std::vector<HtmlElement> elements;
    const size_t indent_size = 2;
    HtmlElement() = default;
    HtmlElement(std::string name, std::string text);
    [[nodiscard]] std::string str(size_t indent = 0) const;
    static HtmlBuilder build(std::string root_name);
};
