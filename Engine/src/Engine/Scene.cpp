#include "Engine/Scene.hpp"

using namespace Engine;

Scene::Scene()
{
}

Scene::~Scene()
{
}

entt::registry &Scene::getRegistry()
{
    return _reg;
}
