//
// Created by ryan-i-hadiwijaya on 7/12/18.
//

#ifndef SHAPELEGEND_PLAYERINPUT_HPP
#define SHAPELEGEND_PLAYERINPUT_HPP


#include <src/event/EventObserver.hpp>
#include <src/entity/core/Transform.hpp>

class PlayerInput : public EventObserver {
public:
    PlayerInput(int, Transform*);
    void onEvent(Event) override;
    virtual void up();
    virtual void down();
    virtual void left();
    virtual void right();
protected:
    int id;
    Transform *transform;
};


#endif //SHAPELEGEND_PLAYERINPUT_HPP
