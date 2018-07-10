//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#ifndef SHAPELEGEND_RENDERENGINE_HPP
#define SHAPELEGEND_RENDERENGINE_HPP

class RenderEngine {
public:
    RenderEngine();

    virtual int init() = 0;

    virtual void draw() = 0;

    virtual void clear() = 0;
};

#endif //SHAPELEGEND_RENDERENGINE_HPP
