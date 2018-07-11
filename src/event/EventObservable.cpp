//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#include <iostream>
#include <src/common/Logger.hpp>

#include "EventObservable.hpp"

EventObservable::EventObservable() {
    eventObservers.clear();
}

void EventObservable::addObserver(EventObserver *eventObserver) {
    eventObservers.push_back(eventObserver);
}

void EventObservable::removeObserver(EventObserver *eventObserver) {
    //TODO fix optimize
    for (auto it = eventObservers.begin(); it != eventObservers.end(); it++) {
        if (*it == eventObserver) {
            eventObservers.erase(it);
            break;
        }
    }
}

void EventObservable::notify(Event event) {
    if (event.getValue() != Event::NULL_EVENT) {
        Logger::debug("notify called");
        for (auto eventObserver : eventObservers) {
            Logger::debug("notify to observer called");
            eventObserver->onEvent(event);
        }
    }
}
