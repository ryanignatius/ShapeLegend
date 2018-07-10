//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#ifndef SHAPELEGEND_EVENTOBSERVABLE_HPP
#define SHAPELEGEND_EVENTOBSERVABLE_HPP

#include "EventObserver.hpp"

#include <iostream>
#include <vector>

class EventObservable {
public:
    EventObservable();

    void addObserver(EventObserver*);

    void removeObserver(EventObserver*);

    void notify(Event);

private:
    std::vector<EventObserver*> eventObservers;
};

#endif //SHAPELEGEND_EVENTOBSERVABLE_HPP
