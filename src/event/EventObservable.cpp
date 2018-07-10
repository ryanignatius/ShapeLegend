//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#include <iostream>

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
    std::cout << "notify called" << std::endl;
        for (auto eventObserver : eventObservers) {
            std::cout << "notify to observer called" << std::endl;
            eventObserver->onEvent(event);
        }
    }
}
