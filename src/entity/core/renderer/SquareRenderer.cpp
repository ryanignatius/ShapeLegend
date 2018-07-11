//
// Created by ryan-i-hadiwijaya on 7/11/18.
//

#include <src/entity/World.hpp>
#include "SquareRenderer.hpp"

SquareRenderer::SquareRenderer(Vector3 vec) : Renderer(vec){
}

void SquareRenderer::render(Transform &transform) {
    World::instance().getRenderEngine().drawSquare(transform, color);
}
