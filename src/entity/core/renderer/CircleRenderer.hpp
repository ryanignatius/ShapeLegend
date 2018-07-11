//
// Created by ryan-i-hadiwijaya on 7/11/18.
//

#ifndef SHAPELEGEND_CIRCLERENDERER_HPP
#define SHAPELEGEND_CIRCLERENDERER_HPP


#include "Renderer.hpp"

class CircleRenderer : public Renderer {
public:
    explicit CircleRenderer(Vector3);
    void render(Transform&) override;
};


#endif //SHAPELEGEND_CIRCLERENDERER_HPP
