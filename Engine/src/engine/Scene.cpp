#include <unordered_map>
#include "engine/Scene.hpp"
#include "engine/jsonParse.hpp"
#include "engine/JSONDeserializer.hpp"

using namespace Engine;
namespace json = boost::json;

Scene::Scene(SDL::Renderer &renderer): _texturesLoader(renderer)
{
}

Scene::~Scene()
{
}

entt::registry &Scene::getRegistry()
{
    return _reg;
}

void Scene::loadScene(const std::string &file)
{
    const json::value json = parseJson(file);
    const json::array &objs = json.as_object().at("objects").as_array();

    for (const json::value &obj : objs)
    {
        const uint32_t id = obj.at("id").as_int64();
        const entt::entity e = _reg.create(entt::entity{id});
        const json::array &components = obj.at("components").as_array();
        for (const json::value &component : components)
        {
            const std::string type(component.at("type").as_string());

            if (type == "position")
            {
                Position pos = deserializePosition(component.as_object());
                //auto [x, y, type] = deserializePosition(component.as_object());
                _reg.emplace<Position>(e, pos);
            }
            else if (type == "sprite")
            {
                Sprite sprite = deserializeSprite(component.as_object(), _texturesLoader);
                _reg.emplace<Sprite>(e, sprite);
            }
        }
    }
}
