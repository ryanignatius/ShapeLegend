//
// Created by ryan-i-hadiwijaya on 7/11/18.
//

#ifndef SHAPELEGEND_LOGGER_HPP
#define SHAPELEGEND_LOGGER_HPP

#include <iostream>

class Logger {
public:
    static void debug(std::string s);
    static void info(std::string s);
    static void warn(std::string s);
    static void error(std::string s);
};

#endif //SHAPELEGEND_LOGGER_HPP
