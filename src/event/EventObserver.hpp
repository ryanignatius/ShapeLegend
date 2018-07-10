//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#ifndef SHAPELEGEND_EVENTOBSERVER_HPP
#define SHAPELEGEND_EVENTOBSERVER_HPP

#include "Event.hpp"

class EventObserver {
public:
    virtual void onEvent(Event) = 0;
};

#endif //SHAPELEGEND_EVENTOBSERVER_HPP
