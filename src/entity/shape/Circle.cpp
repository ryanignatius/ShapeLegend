//
// Created by ryan-i-hadiwijaya on 7/12/18.
//

#include <src/entity/core/renderer/CircleRenderer.hpp>
#include "Circle.hpp"

Circle::Circle(Vector3 col) : Shape() {
    setRenderer(new CircleRenderer(col));
}

Circle::Circle() {
    Vector3 col;
    setRenderer(new CircleRenderer(col));
}
