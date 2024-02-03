#include <HtmlElement.h>
#include <HtmlBuilder.h>

#include <utility>

std::string HtmlElement::str(size_t indent) const
{
    std::ostringstream oss;
    std::string i(indent_size * indent, ' ');
    oss << i << "<" << name << ">" << std::endl;
    if (!text.empty()) {
        oss << std::string(indent_size * (indent + 1), ' ') << text << std::endl;
    }
    for (const auto& e : elements) {
        oss << e.str(indent + 1);
    }
    oss << i << "</" << name << ">" << std::endl;
    return oss.str();
}

HtmlBuilder HtmlElement::build(std::string root_name)
{
    return HtmlBuilder(std::move(root_name));
}

HtmlElement::HtmlElement(std::string name, std::string text) : name(std::move(name)), text(std::move(text))
{
}
