//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#ifndef SHAPELEGEND_EVENT_HPP
#define SHAPELEGEND_EVENT_HPP

class Event {
public:
    static const int NULL_EVENT = 0;
    static const int ESCAPE_EVENT = 1;

    static const int UP = 1<<1;
    static const int DOWN = 1<<2;
    static const int LEFT = 1<<3;
    static const int RIGHT = 1<<4;

    static const int PLAYER1_UP_EVENT = 10000 + UP;
    static const int PLAYER1_DOWN_EVENT = 10000 + DOWN;
    static const int PLAYER1_LEFT_EVENT = 10000 + LEFT;
    static const int PLAYER1_RIGHT_EVENT = 10000 + RIGHT;
    static const int PLAYER2_UP_EVENT = 20000 + UP;
    static const int PLAYER2_DOWN_EVENT = 20000 + DOWN;
    static const int PLAYER2_LEFT_EVENT = 20000 + LEFT;
    static const int PLAYER2_RIGHT_EVENT = 20000 + RIGHT;
    static const int PLAYER3_UP_EVENT = 30000 + UP;
    static const int PLAYER3_DOWN_EVENT = 30000 + DOWN;
    static const int PLAYER3_LEFT_EVENT = 30000 + LEFT;
    static const int PLAYER3_RIGHT_EVENT = 30000 + RIGHT;
    static const int PLAYER4_UP_EVENT = 40000 + UP;
    static const int PLAYER4_DOWN_EVENT = 40000 + DOWN;
    static const int PLAYER4_LEFT_EVENT = 40000 + LEFT;
    static const int PLAYER4_RIGHT_EVENT = 40000 + RIGHT;

    Event(int);

    int getValue();

private:
    int value;
};

#endif //SHAPELEGEND_EVENT_HPP
