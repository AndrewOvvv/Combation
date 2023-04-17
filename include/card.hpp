#include <string>

#include "shell.hpp"
#include "element.hpp"


#pragma once


namespace card 
{

class Card {
private:
    std::string name_{};
    std::string decription_{};

    shell::Shell shell_;
    element::Element element_;
    // name - NAME of card (for output, debugging, domestic using and for user)
    // decription - string describes Card (especially for players)
    // shell_ - contains card's shell 
    // element_ - contains card's element
public:
    std::string name() const {
        return name_;
    } // return Card::name_ 
    
    std::string decription() const {
        return decription_;
    } // return Card::decription_

}; // class Card

} // namespace card

