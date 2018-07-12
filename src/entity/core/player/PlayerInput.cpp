//
// Created by ryan-i-hadiwijaya on 7/12/18.
//

#include <src/common/Time.hpp>
#include <src/common/Logger.hpp>
#include "PlayerInput.hpp"

void PlayerInput::onEvent(Event event) {
    int ev = event.getValue();
    if (ev >= 10000) {
        // player input
        if (ev / 10000 == id) {
            ev %= 10000;
            // this player input
            if (ev & Event::UP) up();
            else if (ev & Event::DOWN) down();
            else if (ev & Event::LEFT) left();
            else if (ev & Event::RIGHT) right();
        }
    }
}

PlayerInput::PlayerInput(int ids, Transform *trans) : id(ids), transform(trans) {
}

void PlayerInput::up() {
    Logger::debug("up");
    transform->Translate(0, (float) Time::deltaTime, 0);
}
void PlayerInput::down() {
    Logger::debug("down");
    transform->Translate(0, -(float) Time::deltaTime, 0);
}
void PlayerInput::left() {
    Logger::debug("left");
    transform->Translate(-(float) Time::deltaTime, 0, 0);
}
void PlayerInput::right() {
    Logger::debug("right");
    transform->Translate((float) Time::deltaTime, 0, 0);
}
