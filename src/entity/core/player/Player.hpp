//
// Created by ryan-i-hadiwijaya on 7/12/18.
//

#ifndef SHAPELEGEND_PLAYER_HPP
#define SHAPELEGEND_PLAYER_HPP


#include <src/entity/shape/Shape.hpp>
#include "PlayerInput.hpp"

class Player {
public:
    Player();
    void setShape(Shape*);
    void setPlayerInput(PlayerInput*);
private:
    Shape *shape;
    PlayerInput *playerInput;
};


#endif //SHAPELEGEND_PLAYER_HPP
