//
// Created by ryan-i-hadiwijaya on 7/16/18.
//

#ifndef SHAPELEGEND_TRIANGLEMOVE_HPP
#define SHAPELEGEND_TRIANGLEMOVE_HPP


#include "PlayerMove.hpp"

class TriangleMove : public PlayerMove {
public:
    explicit TriangleMove(Transform*);
    void up() override;
    void down() override;
    void left() override;
    void right() override;
    void upleft() override;
    void upright() override;
    void downleft() override;
    void downright() override;
};


#endif //SHAPELEGEND_TRIANGLEMOVE_HPP
