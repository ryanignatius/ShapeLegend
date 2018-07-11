//
// Created by ryan-i-hadiwijaya on 7/10/18.
//
#include "RenderEngine.hpp"

RenderEngine::RenderEngine() = default;

void RenderEngine::addEntity(BaseEntity *entity) {
    entityList.push_back(entity);
}
