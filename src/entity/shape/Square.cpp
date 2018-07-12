//
// Created by ryan-i-hadiwijaya on 7/12/18.
//

#include <src/entity/core/renderer/SquareRenderer.hpp>
#include "Square.hpp"

Square::Square(Vector3 col) : Shape() {
    setRenderer(new SquareRenderer(col));
}

Square::Square() {
    Vector3 col;
    setRenderer(new SquareRenderer(col));
}
