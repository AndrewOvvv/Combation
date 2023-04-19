#include <string>
#include <memory>

#include "effect.hpp"

#pragma once


namespace effect
{

enum class EffectType {
    time_freezing,
    health_change,
    turn_skip,
    none
};

class PriorityEffect {
private:
    using effect_t = std::shared_ptr<Effect>;

    EffectType type_{EffectType::none};
    int64_t group_priority_{};
    effect_t effect_{};
public:
    /// @brief default constructor, type_ = none, group_priority_ = 0, effect_ = default
    PriorityEffect() = default;

    /// @brief constructor from EffectType, int64_t and Effect 
    /// @param type: EffectType for PriorityEffect
    /// @param priority: int64_t(priority) for group_priority 
    /// @param effect: Effect for PriorityEffect
    PriorityEffect(EffectType type, int64_t priority, Effect effect) {
        type_ = type;
        group_priority_ = priority;
        effect_ = std::make_shared<Effect>(effect);
    }

    /// @brief constructor from EffectType, int64_t and std::shared_ptr<Effect>
    /// @param type: EffectType for PriorityEffect
    /// @param priority: int64_t(priority) for group_priority 
    /// @param effect_ptr: std::sgared_ptr<Effect> for PriorityEffect
    PriorityEffect(EffectType type, int64_t priority, effect_t effect_ptr) {
        type_ = type;
        group_priority_ = priority;
        effect_ = effect_ptr;
    }

    // GETTERS
    /// @brief get type of PriorityEffect
    /// @return type of PriorityEffect
    auto type() const {
        return type_;
    }

    /// @brief get priority number of effect in group
    /// @return group priority number of PriorityEffect
    auto group_priority() const {
        return group_priority_;
    }

    /// @brief get effect of PriorityEffect
    /// @return effect of PriorityEffect
    auto effect() const {
        return effect_;
    }

    // SETTERS
    /// @brief set type_ on new_type
    /// @param new_type: new value of type_ member
    void type(auto new_type) {
        type_ = new_type;
    } 

    /// @brief set group_priority_ on new_priority
    /// @param new_priority: new value of group_priority_ member
    void group_priority(auto new_priority) {
        group_priority_ = new_priority;
    }

    /// @brief set effect_ on new_effect
    /// @param new_effect: new value of effect_ member
    void effect(auto new_effect) {
        effect_ = new_effect;
    }


    // COMPARISON OPERATORS 
    bool operator==(const PriorityEffect &other) const {
        return (type_ == other.type_) && (group_priority_ == other.group_priority_) && (effect_ == other.effect_);
    }

    bool operator<(const PriorityEffect &other) const {
        if (type_ == other.type_) {
            if (group_priority_ == other.group_priority_) {
                return false;
            }
            return group_priority_ < other.group_priority_;
        }
        return type_ < other.type_;
    }

    bool operator>(const PriorityEffect &other) const {
        return !((other < *this) || (other == *this));
    }

    bool operator<=(const PriorityEffect &other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>=(const PriorityEffect &other) const {
        return (*this > other) || (*this == other);
    }
};

} // namespace effect