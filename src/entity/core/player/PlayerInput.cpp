//
// Created by ryan-i-hadiwijaya on 7/12/18.
//

#include <src/common/Time.hpp>
#include <src/common/Logger.hpp>
#include "PlayerInput.hpp"

void PlayerInput::onEvent(Event event) {
    int ev = event.getValue();
    if (ev & Event::UP) {
        if (ev & Event::LEFT) playerMove->upleft();
        else if (ev & Event::RIGHT) playerMove->upright();
        else playerMove->up();
    } else if (ev & Event::DOWN) {
        if (ev & Event::LEFT) playerMove->downleft();
        else if (ev & Event::RIGHT) playerMove->downright();
        else playerMove->down();
    } else if (ev & Event::LEFT) {
        playerMove->left();
    } else if (ev & Event::RIGHT) {
        playerMove->right();
    }
}

PlayerInput::PlayerInput(int ids, PlayerMove *pmove) : id(ids), playerMove(pmove) {
}
