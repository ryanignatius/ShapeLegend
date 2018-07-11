//
// Created by ryan-i-hadiwijaya on 7/11/18.
//

#ifndef SHAPELEGEND_RENDERER_HPP
#define SHAPELEGEND_RENDERER_HPP

#include "src/entity/core/Transform.hpp"
#include "src/entity/core/Vector3.hpp"

class Renderer {
public:
    explicit Renderer(Vector3);
    virtual void render(Transform&) = 0;
protected:
    Vector3 color;
};

#endif //SHAPELEGEND_RENDERER_HPP
