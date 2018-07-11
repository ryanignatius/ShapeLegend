//
// Created by ryan-i-hadiwijaya on 7/11/18.
//

#include "Transform.hpp"

Transform::Transform() {
    position = new Vector3();
    rotation = new Vector3();
    scale = new Vector3(1, 1, 1);
}

Vector3 &Transform::getPosition() {
    return *position;
}

Vector3 &Transform::getRotation() {
    return *rotation;
}

Vector3 &Transform::getScale() {
    return *scale;
}

void Transform::setPosition(Vector3 &newPos) {
    *position = newPos;
}

void Transform::setRotation(Vector3 &newRot) {
    *rotation = newRot;
}

void Transform::setScale(Vector3 &newScale) {
    *scale = newScale;
}

void Transform::Translate(float dx, float dy, float dz) {
    Vector3 vec(getPosition().x + dx, getPosition().y + dy, getPosition().z + dz);
    setPosition(vec);
}

void Transform::Rotate(float dx, float dy, float dz) {
    Vector3 vec(getRotation().x + dx, getRotation().y + dy, getRotation().z + dz);
    setRotation(vec);
}
