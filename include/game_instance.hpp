#include <string>
#include <vector>

#include "player.hpp"
#include "board.hpp"

#pragma once


namespace Game 
{

enum class GameState 
{
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

    bool is_finished() const {
        return state_ == GameState::finished;
    }
    // state_ methods


    // main methods
    void start() {}

    void start_turn() {}

    void finish_turn() {}
    // main methods

}; // class GameInstance

} // namespace Game


