#include <set>
#include <queue>
#include <string>
#include <vector>
#include <stdint.h>
#include <algorithm>

#include "effect.hpp"
#include "shell.hpp"
#include "element.hpp"
#include "priority_effect.hpp"
#include "card.hpp"

#pragma once


namespace Game
{

class Player {
private:
    using card_t = std::shared_ptr<card::Card>;
    using shell_t = std::shared_ptr<shell::Shell>;
    using element_t = std::shared_ptr<element::Element>;
    using effect_t = std::shared_ptr<effect::Effect>;
    using priority_effect_t = effect::PriorityEffect;
    
    const int64_t draw_value = 2; // count of drawing cards
    const int64_t fatigue_value = 2; // damage for trying to draw a missing card
        
    int64_t hp_{};
    int64_t count_shell_draw{draw_value};
    int64_t count_element_draw{draw_value};
    std::vector<shell_t> shell_deck_;
    std::vector<element_t> element_deck_;

    std::vector<shell_t> shell_hand_;
    std::vector<element_t> element_hand_;

    std::set<priority_effect_t> current_effects_;

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
    void apply_effects() {
        
        // apply effects
        int64_t usual_decrease = -1;
        int64_t additional_draw_shell_value{0}, additional_draw_element_value{0};
        bool skip_turn = false, time_stopped = false;

        for (auto set_iterator = current_effects_.begin(); set_iterator != current_effects_.end(); ++set_iterator) {
            if ((*set_iterator).effect()->duration() > 0) {
                apply_effect((*set_iterator).effect(), usual_decrease, 
                            additional_draw_element_value, additional_draw_shell_value,
                            skip_turn, time_stopped);
            }
            if (hp_ <= 0) {
                kill();
            }
            if (time_stopped) {
                continue;
                // TODO
                // finish_turn();
            }
        }

        // cards drawing start
        int64_t current_element_draw = count_element_draw + additional_draw_element_value;
        int64_t current_shell_draw = count_shell_draw + additional_draw_shell_value;
        current_element_draw = std::max(current_element_draw, (int64_t)0);
        current_shell_draw = std::max(current_shell_draw, (int64_t)0);

        while (current_element_draw--) {
            draw_element();
        }

        while (current_shell_draw--) {
            draw_shell();
        }
        // cards draawing end


        // find set elements for deletion
        std::vector<priority_effect_t> for_deletion;
        for (auto set_iterator = current_effects_.begin(); set_iterator != current_effects_.end(); ++set_iterator) {
            if ((*set_iterator).effect()->duration() == 0) {
                for_deletion.push_back(*set_iterator);
            }
        }

        // deletion part
        for (const auto &element : for_deletion) {
            current_effects_.erase(current_effects_.find(element));
        }
    }

    /// @brief change hp, decrease effect's duration on decrease_num
    void apply_effect(effect_t effect, int64_t decrease_num, 
                        int64_t &element_add, int64_t &shell_add,
                        bool &skip_turn, bool &time_stopped) {
        change_hp(effect->hp_changing());
        element_add += effect->element_draw_change();
        shell_add += effect->shell_draw_change();
        skip_turn |= effect->skip_turn();
        time_stopped |= effect->time_stopped();
        effect->change_duration(decrease_num);

        if (!is_alive()) {
            kill();
        }
    }

    /// @brief 
    void turn() {}

    void kill() {}

    void draw_element() {
        if (element_deck_.size() == 0) {
            deal_fatigue();
            return;
        }
        auto get = element_deck_.back();
        element_deck_.pop_back();
        element_hand_.push_back(get);
    }

    void draw_shell() {
        if (shell_deck_.size() == 0) {
            deal_fatigue();
            return;
        }
        auto get = shell_deck_.back();
        shell_deck_.pop_back();
        shell_hand_.push_back(get);
    }

    void deal_fatigue() {
        change_hp(-fatigue_value);
        if (!is_alive()) {
            kill();
        }
    }
}; // class Player

} // namespace Game
