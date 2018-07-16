//
// Created by ryan-i-hadiwijaya on 7/16/18.
//

#include <src/common/Time.hpp>
#include "CircleMove.hpp"

CircleMove::CircleMove(Transform *trans) : PlayerMove(trans) {
    speed = 3;
}

void CircleMove::up() {
    transform->Translate(0, getMovementUnit(), 0);
}

void CircleMove::down() {
    transform->Translate(0, -getMovementUnit(), 0);
}

void CircleMove::left() {
    transform->Translate(-getMovementUnit(), 0, 0);
}

void CircleMove::right() {
    transform->Translate(getMovementUnit(), 0, 0);
}

void CircleMove::upleft() {
    up();
    left();
}

void CircleMove::upright() {
    up();
    right();
}

void CircleMove::downleft() {
    down();
    left();
}

void CircleMove::downright() {
    down();
    right();
}
