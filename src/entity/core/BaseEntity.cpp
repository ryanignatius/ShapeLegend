//
// Created by ryan-i-hadiwijaya on 7/11/18.
//

#include "BaseEntity.hpp"

BaseEntity::BaseEntity() : active(true), renderer(nullptr) {

}

bool BaseEntity::isActive() {
    return active;
}

bool BaseEntity::isRender() {
    return renderer != nullptr;
}

Renderer &BaseEntity::getRenderer() {
    return *renderer;
}

Transform &BaseEntity::getTransform() {
    return transform;
}

void BaseEntity::setTransform(Transform &newTransform) {
    transform = newTransform;
}

void BaseEntity::setRenderer(Renderer *newRenderer) {
    renderer = newRenderer;
}
