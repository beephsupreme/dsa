#include <HtmlBuilder.h>

HtmlBuilder& HtmlBuilder::add_child(std::string child_name, std::string child_text)
{
    HtmlElement e{ std::move(child_name), std::move(child_text) };
    root.elements.emplace_back(e);
    return *this;
}

HtmlBuilder::operator HtmlElement() const
{
    return root;
}

HtmlBuilder::HtmlBuilder(std::string root_name)
{
    root.name = std::move(root_name);
}

std::string HtmlBuilder::str() const
{
    return root.str();
}
