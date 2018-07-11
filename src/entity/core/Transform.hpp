//
// Created by ryan-i-hadiwijaya on 7/11/18.
//

#ifndef SHAPELEGEND_TRANSFORM_HPP
#define SHAPELEGEND_TRANSFORM_HPP

#include "Vector3.hpp"

class Transform {
public:
    Transform();
    Vector3 &getPosition();
    Vector3 &getRotation();
    Vector3 &getScale();
    void setPosition(Vector3&);
    void setRotation(Vector3&);
    void setScale(Vector3&);
    void Translate(float, float, float);
    void Rotate(float, float, float);
private:
    Vector3 *position;
    Vector3 *rotation;
    Vector3 *scale;
};

#endif //SHAPELEGEND_TRANSFORM_HPP
