//
// Created by ryan-i-hadiwijaya on 7/12/18.
//

#include "Time.hpp"
#include "Logger.hpp"

time_point<high_resolution_clock> Time::startTime = high_resolution_clock::now();
long double Time::deltaTime = 0;

void Time::updateTime() {
    Time::deltaTime = duration<long double>(high_resolution_clock::now() - Time::startTime).count();
    Logger::debug("delta time: " + std::to_string(Time::deltaTime) + " seconds");
    Time::startTime = high_resolution_clock::now();
}
