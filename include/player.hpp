#include <string>

#include "card.hpp"


#pragma once


namespace Game
{

class Player {
private:
    long long hp_;
    std::vector<card::Card> hand_;
    std::vector<card::Card> deck_;


public:
};

} // namespace Game
