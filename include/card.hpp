#include <string>
#include <memory>

#include "shell.hpp"
#include "element.hpp"

#pragma once


namespace card 
{

class Card {
private:
    using shell_t = std::shared_ptr<shell::Shell>;
    using element_t = std::shared_ptr<element::Element>;

    std::string name_{};
    std::string description_{};

    shell_t shell_{};
    shell_t element_{};
    // name - NAME of card (for output, debugging, domestic using and for user)
    // decription - string describes Card (especially for players)
    // shell_ - contains card's shell 
    // element_ - contains card's element
public:

    // GETTER
    /// @brief get name of card
    /// @return name of card
    std::string name() const {
        return name_;
    }
    
    /// @brief get description of card
    /// @return description of card
    std::string description() const {
        return description_;
    }
}; // class Card

} // namespace card

