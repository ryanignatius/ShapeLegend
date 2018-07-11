//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#include "World.hpp"
#include "src/engine/render/OpenGLRenderEngine.hpp"
#include "src/engine/input/OpenGLPCInputEngine.hpp"

World::World() {
    err = 0;
    gameEngine = new GameEngine();
    eventObservable = new EventObservable();

#if USE_ENGINE == OPEN_GL
    OpenGLRenderEngine *openGLRenderEngine = new OpenGLRenderEngine();
    if (openGLRenderEngine->init() == 0) {
        eventObservable->addObserver(openGLRenderEngine);
        renderEngine = openGLRenderEngine;
        inputEngine = new OpenGLPCInputEngine(openGLRenderEngine->getWindow());
    } else {
        err = 1;
    }
//#elif USE_RENDER_ENGINE == DIRECT3D
    // not implemented yet..
    //renderEngine = ...
#endif
}

RenderEngine& World::getRenderEngine() {
    return *renderEngine;
}

EventObservable &World::getEventObservable() {
    return *eventObservable;
}

InputEngine &World::getInputEngine() {
    return *inputEngine;
}

GameEngine &World::getGameEngine() {
    return *gameEngine;
}

World &World::instance() {
    static World instance;
    return instance;
}
