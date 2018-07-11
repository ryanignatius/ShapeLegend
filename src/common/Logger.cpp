//
// Created by ryan-i-hadiwijaya on 7/11/18.
//

#include "Logger.hpp"
#include "../configuration/Configuration.hpp"

void Logger::debug(std::string s) {
#if DEBUG_LEVEL <= 1
    std::cout << "[DEBUG]: " << s << std::endl;
#endif
}

void Logger::info(std::string s) {
#if DEBUG_LEVEL <= 2
    std::cout << "[INFO]: " << s << std::endl;
#endif
}

void Logger::warn(std::string s) {
#if DEBUG_LEVEL <= 3
    std::cout << "[WARN]: " << s << std::endl;
#endif
}

void Logger::error(std::string s) {
#if DEBUG_LEVEL <= 4
    std::cout << "[ERROR]: " << s << std::endl;
#endif
}
