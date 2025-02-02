#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <memory>
#include <boost/json.hpp>
#include "App.hpp"
#include "engine/Scene.hpp"
#include "engine/Camera.hpp"

namespace Engine
{
    class Core
    {
    public:
        Core();
        void mainLoop();

    private:
        void startup();

    private:
        SDL::App _app;
        Scene _scene;
        Camera _camera;
    };
}

#endif
