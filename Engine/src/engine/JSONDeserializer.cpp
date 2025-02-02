#include <iostream>
#include <exception>
#include "engine/JSONDeserializer.hpp"
#include "engine/TexturesLoader.hpp"

namespace json = boost::json;

Vec2f deserializeVec2f(const json::object &obj)
{
    return {
        static_cast<float>(obj.at("x").as_double()),
        static_cast<float>(obj.at("y").as_double())
    };
}

RectI deserializeRectI(const json::object &obj)
{
    return {
        static_cast<int>(obj.at("x").as_int64()),
        static_cast<int>(obj.at("y").as_int64()),
        static_cast<int>(obj.at("width").as_int64()),
        static_cast<int>(obj.at("height").as_int64()),
    };
}

RectF deserializeRectF(const json::object &obj)
{
    return {
        static_cast<float>(obj.at("x").as_double()),
        static_cast<float>(obj.at("y").as_double()),
        static_cast<float>(obj.at("width").as_double()),
        static_cast<float>(obj.at("height").as_double()),
    };
}

Engine::Position deserializePosition(const json::object &obj)
{
    json::object::const_iterator objIt = obj.find("type");
    if (objIt == obj.end())
    {
        std::cerr << "Cannot find type of JSON object\n";
        throw std::runtime_error("Object type field not found");
    }
    if (objIt->value().as_string() != "position")
    {
        std::cerr << "Given component is not a position\n";
        throw std::runtime_error("Component is not a Position");
    }

    const float x = obj.at("x").as_double();
    const float y = obj.at("y").as_double();

    return {x, y};
}

Engine::Sprite deserializeSprite(const json::object &obj, TexturesLoader &texturesLoader)
{
    json::object::const_iterator objIt = obj.find("type");
    if (objIt == obj.end())
    {
        std::cerr << "Cannot find type of JSON object\n";
        throw std::runtime_error("Object type field not found");
    }
    if (objIt->value().as_string() != "sprite")
    {
        std::cerr << "Given component is not a Sprite\n";
        throw std::runtime_error("Component is not a Sprite");
    }

    Engine::Sprite sprite;

    sprite.hidden = obj.at("hidden").as_bool();
    sprite.scale = deserializeVec2f(obj.at("scale").as_object());
    sprite.textureRect = deserializeRectI(obj.at("texture_rect").as_object());
    sprite.rect = deserializeRectF(obj.at("rect").as_object());
    sprite.angle = obj.at("angle").as_double();

    const json::string &flipStr = obj.at("flip").as_string();
    if (flipStr == "horizontal")
    {
        sprite.flip = SDL_FLIP_HORIZONTAL;
    }
    else if (flipStr == "vertical")
    {
        sprite.flip = SDL_FLIP_VERTICAL;
    }

    sprite.texture = texturesLoader.getTexture(obj.at("texture").as_string().c_str());
    sprite.alpha = obj.at("alpha").as_int64();

    std::cout << "rect: " << sprite.rect << " texture_rect: " << sprite.textureRect << std::endl;

    return sprite;
}

