#include <map>
#include <string>

#pragma once


namespace element
{


enum class ElementType
{
    none,
    fire,
    water,
    earth,
    wind,
    light,
    dark
}; // enum class ElementType


class Element 
{
private:
    std::string name_{};
    std::string description_{};
    ElementType type_{ElementType::none};
    // name - NAME of element (for output, debugging, domestic using and for user)
    // decription - string describes Element (especially for players)
public:
    Element() = default;

    // GETTERS
    /// @brief get name of element 
    /// @return name of element
    std::string name() const {
        return name_;
    }
    
    /// @brief get description of element
    /// @return description of element
    std::string description() const {
        return description_;
    }

    /// @brief get type of element
    /// @return type of element
    ElementType type() const {
        return type_;
    }

}; // class Element

} // namespace element
