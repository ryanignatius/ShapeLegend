//
// Created by ryan-i-hadiwijaya on 7/11/18.
//

#ifndef SHAPELEGEND_SQUARERENDERER_HPP
#define SHAPELEGEND_SQUARERENDERER_HPP


#include "Renderer.hpp"

class SquareRenderer : public Renderer {
public:
    explicit SquareRenderer(Vector3);
    void render(Transform&) override;
};


#endif //SHAPELEGEND_SQUARERENDERER_HPP
