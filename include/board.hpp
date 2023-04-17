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
    int64_t hp_{};
    
    element::Element* state_;
    
    std::vector<effect::Effect*> current_effects_;
public:
    auto hp() const {
        return hp_;
    } // return Board::hp_
    
    // TODO
    void apply_effects() {} // no return value; just apply effects
}; // class Board

} // namespace Game
