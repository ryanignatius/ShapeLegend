//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#ifndef SHAPELEGEND_INPUTENGINE_HPP
#define SHAPELEGEND_INPUTENGINE_HPP

#include "../../event/Event.hpp"

class InputEngine {
public:
    virtual Event getInput() = 0;
};

#endif //SHAPELEGEND_INPUTENGINE_HPP
