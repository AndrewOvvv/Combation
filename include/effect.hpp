#include <string>
#include <memory>

#pragma once


namespace effect
{

class Effect {
private:
    int64_t duration_{};
    int64_t hp_change_{};

    int64_t shell_draw_change_{};
    int64_t element_draw_change_{};

    bool skip_turn_{false};
    bool time_stopped_{false};
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

    /// @brief get skip_turn_ flag value
    /// @return value of skipping turn flag
    auto skip_turn() const {
        return skip_turn_;
    }

    /// @brief get time_stopped_ flag value
    /// @return value of time stopped flag
    auto time_stopped() const {
        return time_stopped_;
    }

    /// @brief change effect duration on deltha_value
    /// @param deltha_value: value for changing
    auto change_duration(int64_t deltha_value) {
        duration_ += deltha_value;
    } 
}; // class Effect

} // namespace effect