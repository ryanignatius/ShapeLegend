//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#ifndef SHAPELEGEND_EVENT_HPP
#define SHAPELEGEND_EVENT_HPP

class Event {
public:
    static const int NULL_EVENT = 0;
    static const int ESCAPE_EVENT = 1;

    Event(int);

    int getValue();

private:
    int value;
};

#endif //SHAPELEGEND_EVENT_HPP
