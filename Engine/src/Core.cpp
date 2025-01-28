#include "Core.hpp"
#include <SDL2/SDL_events.h>

#include "App.hpp"

#include "Engine/WinInfo.hpp"
#include "Timer.hpp"

#include "systems/RenderSystem.hpp"
#include "systems/AnimationSystem.hpp"
#include "systems/TilemapSystem.hpp"
#include "systems/CollisionSystem.hpp"
#include "systems/MovementSystem.hpp"

using namespace Engine;

Core::Core() : _app(1600, 900), _camera({0, 0, 0, 0})
{
    WinInfo::getInstance().setApp(&_app);
    WinInfo::getInstance().setWindowSize({1600, 900});
}

void Core::mainLoop()
{
    bool quit = false;
    SDL_Event e;

    Timer frameTimer;
    Timer animTimer;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            if (e.type == SDL_MOUSEMOTION)
            {
                WinInfo::getInstance().setMousePos(e.motion.x, e.motion.y);
            }
        }
        
        entt::registry &reg = _scene->getRegistry();

        _app.getRenderer().setDrawColor(50, 50, 50, 0);
        _app.getRenderer().clear();

        moveObjects(reg, frameTimer.getDeltaTime());
        animateSprites(reg, animTimer.getDeltaTime());
        handleCollisions(reg);

        frameTimer.start();

        drawMap(reg, _app.getRenderer(), _camera);
        updateRenderSystem(reg, _app.getRenderer(), _camera, false);

        _app.getRenderer().present();
    }
}
