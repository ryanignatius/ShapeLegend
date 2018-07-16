#include <src/entity/core/renderer/TriangleRenderer.hpp>
#include <src/entity/core/renderer/CircleRenderer.hpp>
#include <src/entity/core/renderer/SquareRenderer.hpp>
#include <src/entity/shape/Triangle.hpp>
#include <src/entity/shape/Circle.hpp>
#include <src/entity/shape/Square.hpp>
#include <src/entity/core/player/Player.hpp>
#include "src/entity/World.hpp"

int main()
{
    if (World::instance().err != 0) {
        return -1;
    }

    //test triangle
    Player q1;
    Triangle p1(Vector3(1, 0, 0));
    p1.getTransform().Translate(-5, 5, 0);
    World::instance().getRenderEngine().addEntity(&p1);
    q1.setShape(&p1);
    PlayerInput i1(1, &p1.getTransform());
    World::instance().getEventObservable().addObserver(EventObservable::PLAYER1_CHANNEL, &i1);
    q1.setPlayerInput(&i1);

    Triangle p2(Vector3(0, 1, 0));
    p2.getTransform().Translate(0, 5, 0);
    World::instance().getRenderEngine().addEntity(&p2);

    Triangle p3(Vector3(0, 0, 1));
    p3.getTransform().Translate(5, 5, 0);
    World::instance().getRenderEngine().addEntity(&p3);

    //test circle
    Player q4;
    Circle p4(Vector3(1, 0, 0));
    p4.getTransform().Translate(0, 0, 0);
    World::instance().getRenderEngine().addEntity(&p4);
    q4.setShape(&p4);
    PlayerInput i4(2, &p4.getTransform());
    World::instance().getEventObservable().addObserver(EventObservable::PLAYER2_CHANNEL, &i4);
    q4.setPlayerInput(&i4);

    Circle p5(Vector3(0, 1, 0));
    p5.getTransform().Translate(5, 0, 0);
    World::instance().getRenderEngine().addEntity(&p5);

    Circle p6(Vector3(0, 0, 1));
    p6.getTransform().Translate(-5, 0, 0);
    World::instance().getRenderEngine().addEntity(&p6);

    //test square
    Player q7;
    Square p7(Vector3(1, 0, 0));
    p7.getTransform().Translate(5, -5, 0);
    World::instance().getRenderEngine().addEntity(&p7);
    q7.setShape(&p7);
    PlayerInput i7(3, &p7.getTransform());
    World::instance().getEventObservable().addObserver(EventObservable::PLAYER3_CHANNEL, &i7);
    q7.setPlayerInput(&i7);

    Square p8(Vector3(0, 1, 0));
    p8.getTransform().Translate(-5, -5, 0);
    World::instance().getRenderEngine().addEntity(&p8);

    Square p9(Vector3(0, 0, 1));
    p9.getTransform().Translate(0, -5, 0);
    World::instance().getRenderEngine().addEntity(&p9);

    World::instance().getGameEngine().gameLoop();
    return 0;
}
