//
// Created by ryan-i-hadiwijaya on 7/16/18.
//

#ifndef SHAPELEGEND_PLAYERMOVE_HPP
#define SHAPELEGEND_PLAYERMOVE_HPP


#include <src/entity/core/Transform.hpp>

class PlayerMove {
public:
    PlayerMove(Transform*);
    virtual void up() = 0;
    virtual void down() = 0;
    virtual void left() = 0;
    virtual void right() = 0;
    virtual void upleft() = 0;
    virtual void upright() = 0;
    virtual void downleft() = 0;
    virtual void downright() = 0;
    virtual float getMovementUnit();
protected:
    float speed;
    Transform *transform;
};

#endif //SHAPELEGEND_PLAYERMOVE_HPP
