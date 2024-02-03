#pragma once

#include <HtmlElement.h>
#include <utility>

class HtmlBuilder {
private:
    HtmlElement root;
public:
    explicit HtmlBuilder(std::string root_name);
    HtmlBuilder& add_child(std::string child_name, std::string child_text);
    [[nodiscard]] std::string str() const;
    operator HtmlElement() const; // NOLINT(*-explicit-constructor)
};