#include <set>
#include <queue>
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
    using card_t = std::shared_ptr<card::Card>;
    using shell_t = std::shared_ptr<shell::Shell>;
    using element_t = std::shared_ptr<element::Element>;
    using priority_effect_t = std::pair<int64_t, std::shared_ptr<effect::Effect>>;
        
    int64_t hp_{};
    std::vector<shell_t> shell_deck_;
    std::vector<element_t> element_deck_;

    std::vector<shell_t> shell_hand_;
    std::vector<element_t> element_hand_;

    bool cmp(const priority_effect_t &arg1, const priority_effect_t &arg2) { 
        return arg1.first < arg2.first; 
    }

    std::set<priority_effect_t, decltype(cmp)> current_effects_{cmp};

    card_t current_card_;
public:

    // GETTERS

    /// @brief get hp of player
    /// @return hp of player
    auto hp() const {
        return hp_;
    }

    /// @brief get shell deck of player
    /// @return shell deck of player
    auto shell_deck() const {
        return shell_deck_;
    }

    /// @brief get shell hand of player
    /// @return shall hand of player
    auto shell_hand() const {
        return shell_hand_;
    }

    /// @brief get element deck of player
    /// @return element deck of player
    auto element_deck() const {
        return element_deck_;
    }

    /// @brief get element hand of player
    /// @return element hand of player
    auto element_hand() const {
        return element_hand_;
    }

    /// @brief get current effects of player
    /// @return current effects of player
    auto current_effects() const {
        return current_effects_; 
    }


    /// @brief check if player is alive
    /// @return true if player if alive, otherwise false
    bool is_alive() const {
        return hp_ > 0;
    }

    /// @brief change hp of player on deltha_value
    /// @param deltha_value: value of changing hp
    void change_hp(size_t deltha_value) {
        hp_ += deltha_value;
    } 

    /// @brief itterate over current effects of player and apply them in correct order
    void apply_effects() const {} // no return value; apply effects to player
}; // class Player

} // namespace Game
