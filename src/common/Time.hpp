//
// Created by ryan-i-hadiwijaya on 7/12/18.
//

#ifndef SHAPELEGEND_TIME_HPP
#define SHAPELEGEND_TIME_HPP

#include <chrono>

using namespace std::chrono;

class Time {
public:
    static time_point<high_resolution_clock> startTime;
    static long double deltaTime;
    static void updateTime();
};


#endif //SHAPELEGEND_TIME_HPP
