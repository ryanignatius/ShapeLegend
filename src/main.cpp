#include <src/entity/core/renderer/TriangleRenderer.hpp>
#include <src/entity/core/renderer/CircleRenderer.hpp>
#include <src/entity/core/renderer/SquareRenderer.hpp>
#include "src/entity/World.hpp"

int main()
{
    if (World::instance().err != 0) {
        return -1;
    }

    //test triangle
    BaseEntity p1;
    TriangleRenderer r1(Vector3(1, 0, 0));
    p1.setRenderer(&r1);
    p1.getTransform().Translate(-5,5,0);
    World::instance().getRenderEngine().addEntity(&p1);

    BaseEntity p2;
    TriangleRenderer r2(Vector3(0, 1, 0));
    p2.setRenderer(&r2);
    p2.getTransform().Translate(0,5,0);
    World::instance().getRenderEngine().addEntity(&p2);

    BaseEntity p3;
    TriangleRenderer r3(Vector3(0, 0, 1));
    p3.setRenderer(&r3);
    p3.getTransform().Translate(5,5,0);
    World::instance().getRenderEngine().addEntity(&p3);

    //test circle
    BaseEntity p4;
    CircleRenderer r4(Vector3(1, 0, 0));
    p4.setRenderer(&r4);
    p4.getTransform().Translate(0,0,0);
    World::instance().getRenderEngine().addEntity(&p4);

    BaseEntity p5;
    CircleRenderer r5(Vector3(0, 1, 0));
    p5.setRenderer(&r5);
    p5.getTransform().Translate(5,0,0);
    World::instance().getRenderEngine().addEntity(&p5);

    BaseEntity p6;
    CircleRenderer r6(Vector3(0, 0, 1));
    p6.setRenderer(&r6);
    p6.getTransform().Translate(-5,0,0);
    World::instance().getRenderEngine().addEntity(&p6);

    //test square
    BaseEntity p7;
    SquareRenderer r7(Vector3(1, 0, 0));
    p7.setRenderer(&r7);
    p7.getTransform().Translate(5,-5,0);
    World::instance().getRenderEngine().addEntity(&p7);

    BaseEntity p8;
    SquareRenderer r8(Vector3(0, 1, 0));
    p8.setRenderer(&r8);
    p8.getTransform().Translate(-5,-5,0);
    World::instance().getRenderEngine().addEntity(&p8);

    BaseEntity p9;
    SquareRenderer r9(Vector3(0, 0, 1));
    p9.setRenderer(&r9);
    p9.getTransform().Translate(0,-5,0);
    World::instance().getRenderEngine().addEntity(&p9);

    World::instance().getGameEngine().gameLoop();
    return 0;
}
