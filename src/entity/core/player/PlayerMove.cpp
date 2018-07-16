//
// Created by ryan-i-hadiwijaya on 7/16/18.
//

#include <src/common/Time.hpp>
#include "PlayerMove.hpp"

PlayerMove::PlayerMove(Transform *trans) : speed(1), transform(trans) {
}

float PlayerMove::getMovementUnit() {
    return speed * (float) Time::deltaTime;
}
