//
// Created by ryan-i-hadiwijaya on 7/11/18.
//

#ifndef SHAPELEGEND_TRIANGLERENDERER_HPP
#define SHAPELEGEND_TRIANGLERENDERER_HPP


#include "Renderer.hpp"

class TriangleRenderer : public Renderer {
public:
    explicit TriangleRenderer(Vector3);
    void render(Transform&) override;
};


#endif //SHAPELEGEND_TRIANGLERENDERER_HPP
