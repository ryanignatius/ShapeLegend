//
// Created by ryan-i-hadiwijaya on 7/16/18.
//

#ifndef SHAPELEGEND_CIRCLEMOVE_HPP
#define SHAPELEGEND_CIRCLEMOVE_HPP


#include "PlayerMove.hpp"

class CircleMove : public PlayerMove {
public:
    explicit CircleMove(Transform*);
    void up() override;
    void down() override;
    void left() override;
    void right() override;
    void upleft() override;
    void upright() override;
    void downleft() override;
    void downright() override;
};

#endif //SHAPELEGEND_CIRCLEMOVE_HPP
