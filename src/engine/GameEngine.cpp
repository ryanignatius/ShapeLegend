//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#include <chrono>
#include <thread>

#include "GameEngine.hpp"
#include "../event/Event.hpp"
#include "../configuration/World.hpp"

void GameEngine::gameLoop() {

    while (true) {
        std::cout << "game loop called" << std::endl;
        Event event = World::instance().getInputEngine().getInput();
        World::instance().getEventObservable().notify(event);
        if (event.getValue() == Event::ESCAPE_EVENT) {
            break;
        }

        //TODO
        //update

        World::instance().getRenderEngine().clear();
        World::instance().getRenderEngine().draw();

        //TODO adjust sleep time
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
    }
}
