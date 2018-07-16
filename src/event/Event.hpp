//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#ifndef SHAPELEGEND_EVENT_HPP
#define SHAPELEGEND_EVENT_HPP

class Event {
public:
    static const int NULL_EVENT = 0;
    static const int ESCAPE_EVENT = -1;

    static const int UP = 1<<1;
    static const int DOWN = 1<<2;
    static const int LEFT = 1<<3;
    static const int RIGHT = 1<<4;
    static const int CONFIRM_EVENT = 1<<5;
    static const int CANCEL_EVENT = 1<<6;

    Event(int);

    int getValue();

private:
    int value;
};

#endif //SHAPELEGEND_EVENT_HPP
