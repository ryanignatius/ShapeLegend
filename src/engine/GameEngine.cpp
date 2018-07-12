//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#include <chrono>
#include <thread>
#include <src/common/Logger.hpp>
#include <src/common/Time.hpp>

#include "GameEngine.hpp"
#include "../event/Event.hpp"
#include "src/entity/World.hpp"

void GameEngine::gameLoop() {

    Time::updateTime();
    while (true) {
        Logger::debug("game loop called");
        Time::updateTime();
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
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}
