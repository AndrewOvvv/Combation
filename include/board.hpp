#include <string>
#include <vector>

#include "shell.hpp"
#include "element.hpp"
#include "effect.hpp"

#pragma once


namespace Game
{

class Board {
private:
    using element_t = std::unique_ptr<element::Element>;
    using effect_t = std::unique_ptr<effect::Effect>;
    
    int64_t hp_{};
    
    element_t state_;
    
    std::vector<effect_t> current_effects_;
public:
    
    // GETTERS
    auto hp() const {
        return hp_;
    } // return Board::hp_
    
    auto state() const {
        return state_;
    } // return Board::state_
    
    // SETTERS
    auto state(element_t new_element) {
        state_ = new_element;
    } // no return value; set new Board::state_ value
    
    // TODO
    void apply_effects() {} // no return value; just apply effects
}; // class Board

} // namespace Game
