//
// Created by ryan-i-hadiwijaya on 7/12/18.
//

#include <src/common/Time.hpp>
#include <src/common/Logger.hpp>
#include "PlayerInput.hpp"

void PlayerInput::onEvent(Event event) {
    int ev = event.getValue();
    if (ev & Event::UP) {
        if (ev & Event::LEFT) upleft();
        else if (ev & Event::RIGHT) upright();
        else up();
    } else if (ev & Event::DOWN) {
        if (ev & Event::LEFT) downleft();
        else if (ev & Event::RIGHT) downright();
        else down();
    } else if (ev & Event::LEFT) {
        left();
    } else if (ev & Event::RIGHT) {
        right();
    }
}

PlayerInput::PlayerInput(int ids, Transform *trans) : id(ids), transform(trans) {
}

void PlayerInput::up() {
    transform->Translate(0, (float) Time::deltaTime, 0);
}
void PlayerInput::down() {
    transform->Translate(0, -(float) Time::deltaTime, 0);
}
void PlayerInput::left() {
    transform->Translate(-(float) Time::deltaTime, 0, 0);
}
void PlayerInput::right() {
    transform->Translate((float) Time::deltaTime, 0, 0);
}
void PlayerInput::upleft() {
    up();
    left();
}
void PlayerInput::upright() {
    up();
    right();
}
void PlayerInput::downleft() {
    down();
    left();
}
void PlayerInput::downright() {
    down();
    right();
}
