//
// Created by ryan-i-hadiwijaya on 7/16/18.
//

#ifndef SHAPELEGEND_SQUAREMOVE_HPP
#define SHAPELEGEND_SQUAREMOVE_HPP


#include "PlayerMove.hpp"

class SquareMove : public PlayerMove {
public:
    explicit SquareMove(Transform*);
    void up() override;
    void down() override;
    void left() override;
    void right() override;
    void upleft() override;
    void upright() override;
    void downleft() override;
    void downright() override;
};


#endif //SHAPELEGEND_SQUAREMOVE_HPP
