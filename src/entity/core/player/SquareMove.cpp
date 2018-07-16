//
// Created by ryan-i-hadiwijaya on 7/16/18.
//

#include <src/common/Time.hpp>
#include "SquareMove.hpp"

SquareMove::SquareMove(Transform *trans) : PlayerMove(trans){
    speed = 5;
}

void SquareMove::up() {
    transform->Translate(0, getMovementUnit(), 0);
}

void SquareMove::down() {
    transform->Translate(0, -getMovementUnit(), 0);
}

void SquareMove::left() {
    transform->Translate(-getMovementUnit(), 0, 0);
}

void SquareMove::right() {
    transform->Translate(getMovementUnit(), 0, 0);
}

void SquareMove::upleft() {
    up();
}

void SquareMove::upright() {
    up();
}

void SquareMove::downleft() {
    down();
}

void SquareMove::downright() {
    down();
}
