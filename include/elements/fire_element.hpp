#include "abstract_element.hpp"


#pragma once

namespace element
{

class FireElement : public AbstractElement
{
private:
public:
    FireElement() : name_("Fire") {}; // set correct name_ and fusion
}; // class FireElement

} // namespace element

