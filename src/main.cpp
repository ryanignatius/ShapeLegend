#include "configuration/World.hpp"

int main()
{
    if (World::instance().err != 0) {
        return -1;
    }
    World::instance().getGameEngine().gameLoop();
    return 0;
}
