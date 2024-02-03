#pragma once

#include <HtmlElement.h>
#include <utility>

struct HtmlBuilder {
    HtmlElement root;
    explicit HtmlBuilder(std::string root_name);
    HtmlBuilder& add_child(std::string child_name, std::string child_text);
    [[nodiscard]] std::string str() const;
    operator HtmlElement() const; // NOLINT(*-explicit-constructor)
};