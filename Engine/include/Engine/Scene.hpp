#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "entt.hpp"

namespace Engine
{
    class Scene
    {
    public:
        Scene();
        ~Scene();

        virtual void start() {};

        entt::registry &getRegistry();

    protected:
        entt::registry _reg;
    };
}

#endif
