#include <memory>
#include <string>
#include <vector>

#include "player.hpp"
#include "board.hpp"

#pragma once


namespace Game 
{

enum class GameState 
{
    begining,
    in_process,
    finished
}; // enum class GameState

class GameInstance {
private:
    std::vector<Player> players_;
    Board board_;

    size_t turn_number_{};
    size_t whos_turn_{};
    
    GameState state_;
    // players - vector contains info about all Players in current game
    // board - contains info about Board (aka GameField)
    // step_number - contains number of turn
    // whos_turn - contains number of player whos turn
    // state - contains state of game
public:
    
    // state_ methods

    /// @brief count alive players after change state of game
    void update_state() {
        size_t cnt_alive = 0;
        for (size_t i = 0; i < players_.size(); ++i) {
            if (players_[i].is_alive()) {
                ++cnt_alive;
            }
        }

        if (cnt_alive > 1) {
            state_ = GameState::in_process;
        } else {
            state_ = GameState::finished;
        }
    }

    /// @brief check if game is finished
    /// @return true if state is finished, otherwise false
    bool is_finished() const {
        return state_ == GameState::finished;
    }

    /// @brief update state after check is game finished
    /// @return return true if after state update game has finished state, otherwise else
    bool check_state() {
        update_state();
        return is_finished();
    }
    // state_ methods


    // main methods
    void start() {
        while (state_ != GameState::finished){
            if (state_ == GameState::begining) {
                // TODO
            } else if (state_ == GameState::in_process) {
                board_.apply_effects();
                if (check_state()) continue;
                players_[whos_turn_].turn();
                if (check_state()) continue;
                whos_turn_ = (whos_turn_ + 1) % players_.size();
            }
        }
    }

    void start_turn() {}

    void finish_turn() {}
    // main methods

}; // class GameInstance

} // namespace Game


