#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <memory>
#include "SDL/App.hpp"
#include "Engine/Scene.hpp"
#include "Engine/Camera.hpp"

namespace Engine
{
    class Core
    {
    public:
        Core();
        void mainLoop();

    private:
        SDL::App _app;
        std::unique_ptr<Scene> _scene;
        Engine::Camera _camera;
    };
}

#endif
