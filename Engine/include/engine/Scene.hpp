#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "entt.hpp"
#include "engine/TexturesLoader.hpp"

namespace Engine
{
    class Scene
    {
    public:
        Scene(SDL::Renderer &renderer);
        ~Scene();

        entt::registry &getRegistry();

        void loadScene(const std::string &file);

    protected:
        entt::registry _reg;
        TexturesLoader _texturesLoader;
    };
}

#endif
