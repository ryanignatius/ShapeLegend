//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#ifndef SHAPELEGEND_WORLD_HPP
#define SHAPELEGEND_WORLD_HPP

#include "../engine/GameEngine.hpp"
#include "../engine/render/RenderEngine.hpp"
#include "../engine/input/InputEngine.hpp"
#include "../event/EventObservable.hpp"

class World {
public:
    static World &instance();

    GameEngine &getGameEngine();

    RenderEngine &getRenderEngine();

    InputEngine &getInputEngine();

    EventObservable &getEventObservable();

    // err != 0 indicates error on initialize world
    //TODO refactor this
    int err;

private:
    World();

    World(World const&);// Don't Implement.

    void operator=(World const&);// Don't Implement.

    GameEngine *gameEngine;

    RenderEngine *renderEngine;

    InputEngine *inputEngine;

    EventObservable *eventObservable;
};

#endif //SHAPELEGEND_WORLD_HPP
