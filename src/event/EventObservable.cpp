//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#include <iostream>
#include <src/common/Logger.hpp>

#include "EventObservable.hpp"

EventObservable::EventObservable() {
    for (int i=0; i<EventObservable::MAX_CHANNEL; i++) {
        eventObservers[i].clear();
    }
}

void EventObservable::addObserver(int channel, EventObserver *eventObserver) {
    eventObservers[channel].push_back(eventObserver);
}

void EventObservable::removeObserver(int channel, EventObserver *eventObserver) {
    //TODO fix optimize
    for (auto it = eventObservers[channel].begin(); it != eventObservers[channel].end(); it++) {
        if (*it == eventObserver) {
            eventObservers[channel].erase(it);
            break;
        }
    }
}

void EventObservable::notify(int channel, Event event) {
    if (event.getValue() != Event::NULL_EVENT) {
        Logger::debug("notify called");
        for (auto eventObserver : eventObservers[channel]) {
            Logger::debug("notify to observer called");
            eventObserver->onEvent(event);
        }
    }
}
