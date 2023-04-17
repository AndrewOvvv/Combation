#include <string>
#include <memory>

#pragma once


namespace effect
{

class Effect {
private:
    size_t duration_{};
    int64_t hp_change_{};

    int64_t shell_draw_change_{};
    int64_t element_draw_change_{};
public:

    // GETTERS
    /// @brief get duration of effect 
    /// @return duration of effect
    auto duration() const {
        return duration_;
    }

    /// @brief get hp changing value of effect
    /// @return hp changing value of effect
    auto hp_changing() const {
        return hp_change_;
    }

    /// @brief get shell draw changing value
    /// @return shell draw changing value
    auto shell_draw_change() const {
        return shell_draw_change_;
    }

    /// @brief get element draw changing value
    /// @return element draw changing value
    auto element_draw_change() const {
        return element_draw_change_;
    }
}; // class Effect

} // namespace effect