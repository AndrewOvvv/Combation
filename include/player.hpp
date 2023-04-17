#include <string>
#include <vector>
#include <stdint.h>

#include "element.hpp"
#include "shell.hpp"
#include "card.hpp"



#pragma once


namespace Game
{

class Player {
private:
    int64_t hp_{};
    std::vector<shell::Shell*> shell_deck_;
    std::vector<element::Element*> element_deck_;

    std::vector<shell::Shell*> shell_hand_;
    std::vector<element::Element*> element_hand_;

    std::priority_queue<int64_t, effect::Effect*> current_effects_;

    card::Card current_card_;
public:

    auto hp() const {
        return hp_;
    } // return Player::hp_ 

    auto shell_deck() const {
        return shell_deck_;
    } // return Player::shell_deck_

    auto shell_hand() const {
        return shell_hand_;
    } // return Player::shell_hand_ 

    auto element_deck() const {
        return element_deck_;
    } // return Player::element_deck_

    auto element_hand() const {
        return element_hand_;
    } // return Player::element_hand_

    auto get_current_effects() const {
        return current_effects_; 
    } // return Player::current_effect

    void change_hp(size_t deltha_value) {
        hp_ += deltha_value;
    } // no return value; change Player::hp_ on deltha

    void apply_effects() const {} // no return value; apply effects to player
}; // class Player

} // namespace Game
