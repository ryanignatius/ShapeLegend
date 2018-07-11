//
// Created by ryan-i-hadiwijaya on 7/11/18.
//

#include <src/entity/World.hpp>
#include "CircleRenderer.hpp"

CircleRenderer::CircleRenderer(Vector3 vec) : Renderer(vec){
}

void CircleRenderer::render(Transform &transform) {
    World::instance().getRenderEngine().drawCircle(transform, color);
}
