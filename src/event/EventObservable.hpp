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
    static const int MAX_CHANNEL = 5;
    static const int GENERAL_CHANNEL = 0;
    static const int PLAYER1_CHANNEL = 1;
    static const int PLAYER2_CHANNEL = 2;
    static const int PLAYER3_CHANNEL = 3;
    static const int PLAYER4_CHANNEL = 4;

    EventObservable();

    void addObserver(int, EventObserver*);

    void removeObserver(int, EventObserver*);

    void notify(int, Event);

private:
    std::vector<EventObserver*> eventObservers[MAX_CHANNEL];
};

#endif //SHAPELEGEND_EVENTOBSERVABLE_HPP
