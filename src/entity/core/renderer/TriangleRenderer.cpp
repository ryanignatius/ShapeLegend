//
// Created by ryan-i-hadiwijaya on 7/11/18.
//

#include <src/entity/World.hpp>
#include "TriangleRenderer.hpp"

#include <iostream>

TriangleRenderer::TriangleRenderer(Vector3 vec) : Renderer(vec) {
}

void TriangleRenderer::render(Transform &transform) {
    World::instance().getRenderEngine().drawTriangle(transform, color);
}
