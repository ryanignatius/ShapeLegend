//
// Created by ryan-i-hadiwijaya on 7/11/18.
//

#ifndef SHAPELEGEND_BASEENTITY_HPP
#define SHAPELEGEND_BASEENTITY_HPP

#include "Transform.hpp"
#include "src/entity/core/renderer/Renderer.hpp"

class BaseEntity {
public:
    BaseEntity();
    bool isActive();
    bool isRender();
    Transform& getTransform();
    Renderer& getRenderer();
    void setTransform(Transform&);
    void setRenderer(Renderer*);
protected:
    bool active;
    Transform transform;
    Renderer *renderer;
};

#endif //SHAPELEGEND_BASEENTITY_HPP
