//
// Created by ryan-i-hadiwijaya on 7/12/18.
//

#ifndef SHAPELEGEND_PLAYERINPUT_HPP
#define SHAPELEGEND_PLAYERINPUT_HPP


#include <src/event/EventObserver.hpp>
#include <src/entity/core/Transform.hpp>
#include "PlayerMove.hpp"

class PlayerInput : public EventObserver {
public:
    PlayerInput(int, PlayerMove*);
    void onEvent(Event) override;
protected:
    int id;
    PlayerMove *playerMove;
};

#endif //SHAPELEGEND_PLAYERINPUT_HPP
