#include <string>
#include <vector>
#include <memory>
#include <queue>

#include "shell.hpp"
#include "element.hpp"
#include "effect.hpp"

#pragma once


namespace Game
{

class Board {
private:
    using element_t = std::shared_ptr<element::Element>;
    using effect_t = std::shared_ptr<effect::Effect>;
    
    int64_t hp_{};
    
    element_t state_;
    
    std::deque<effect_t> current_effects_;
public:
    
    // GETTERS
    /// @brief  get hp of board
    /// @return hp of board
    auto hp() const {
        return hp_;
    }
    
    /// @brief get state of board
    /// @return state of board
    auto state() const {
        return state_;
    }
    
    // SETTERS
    /// @brief set state of board
    /// @param new_element: new value of state member 
    void state(element_t new_element) {
        state_ = new_element;
    }
    
    // TODO

    /// @brief itterate over current effects of board and apply every effect
    void apply_effects() {} // no return value; just apply effects
}; // class Board

} // namespace Game
