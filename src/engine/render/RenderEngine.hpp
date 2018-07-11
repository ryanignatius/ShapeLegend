//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#ifndef SHAPELEGEND_RENDERENGINE_HPP
#define SHAPELEGEND_RENDERENGINE_HPP

#include <src/entity/core/BaseEntity.hpp>

#include <iostream>
#include <vector>

class RenderEngine {
public:
    RenderEngine();

    virtual int init() = 0;

    virtual void draw() = 0;

    virtual void drawTriangle(Transform&, Vector3&) = 0;

    virtual void drawSquare(Transform&, Vector3&) = 0;

    virtual void drawCircle(Transform&, Vector3&) = 0;

    virtual void clear() = 0;

    void addEntity(BaseEntity*);
protected:
    std::vector<BaseEntity*> entityList;
};

#endif //SHAPELEGEND_RENDERENGINE_HPP
