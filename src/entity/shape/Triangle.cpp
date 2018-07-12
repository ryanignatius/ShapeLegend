//
// Created by ryan-i-hadiwijaya on 7/12/18.
//

#include <src/entity/core/renderer/TriangleRenderer.hpp>
#include "Triangle.hpp"

Triangle::Triangle(Vector3 col) : Shape() {
    setRenderer(new TriangleRenderer(col));
}

Triangle::Triangle() : Shape() {
    Vector3 col;
    setRenderer(new TriangleRenderer(col));
}
