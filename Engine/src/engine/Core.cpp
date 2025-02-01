#include "engine/Core.hpp"
#include <SDL2/SDL_events.h>
#include <fstream>
#include <iostream>

#include "App.hpp"

#include "engine/WinInfo.hpp"
#include "Timer.hpp"

#include "systems/RenderSystem.hpp"
#include "systems/AnimationSystem.hpp"
#include "systems/TilemapSystem.hpp"
#include "systems/CollisionSystem.hpp"
#include "systems/MovementSystem.hpp"

using namespace Engine;
namespace json = boost::json;

Core::Core() : _app(1600, 900), _camera({0, 0, 0, 0})
{
    WinInfo::getInstance().setApp(&_app);
    WinInfo::getInstance().setWindowSize({1600, 900});

    startup();
}

json::value Core::parseJson(const std::string &file)
{
    std::ifstream stream{file, std::ios::binary};

    if (!stream.is_open())
    {
        std::cerr << "Could not open " << file << "\n";
        throw "FileOpenError";
    }

    json::stream_parser parser;
    boost::system::error_code ec;

    do
    {
        char buffer[4096];
        stream.read(buffer, sizeof(buffer));
        parser.write(buffer, stream.gcount(), ec);

    } while (!stream.eof());

    if (ec)
    {
        std::cout << ec.what() << "\n";
        throw "FileReadError";
    }
    parser.finish(ec);
    if (ec)
    {
        std::cout << ec.what() << "\n";
        throw "ParseError";
    }
    return parser.release();
}

void Core::startup()
{
    parseJson("data/game.json");
}

void Core::mainLoop()
{
    bool quit = false;
    SDL_Event e;

    Timer frameTimer;
    Timer animTimer;

    entt::registry &reg = _scene.getRegistry();

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
        
        _app.getRenderer().setDrawColor(50, 50, 50, 0);
        _app.getRenderer().clear();

        moveObjects(reg, frameTimer.getDeltaTime());
        animateSprites(reg, animTimer.getDeltaTime());
        handleCollisions(reg);

        frameTimer.start();

        //drawMap(reg, _app.getRenderer(), _camera);
        updateRenderSystem(reg, _app.getRenderer(), _camera, false);

        _app.getRenderer().present();
    }
}
