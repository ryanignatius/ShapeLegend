//
// Created by ryan-i-hadiwijaya on 7/12/18.
//

#include "Player.hpp"

Player::Player() {

}

void Player::setShape(Shape *shap) {
    shape = shap;
}

void Player::setPlayerInput(PlayerInput *pl) {
    playerInput = pl;
}
