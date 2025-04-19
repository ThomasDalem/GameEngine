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

        entt::registry &getRegistry();

        void loadScene(const std::string &file);

    protected:
        entt::registry _reg;
    };
}

#endif
