#ifndef JSON_DESERIALIZER_HPP
#define JSON_DESERIALIZER_HPP

#include <boost/json.hpp>
#include <iostream>
#include "components/Position.hpp"
#include "components/Sprite.hpp"
#include "engine/TexturesLoader.hpp"

Engine::Position deserializePosition(const boost::json::object &obj);
Engine::Sprite deserializeSprite(const boost::json::object &obj, TexturesLoader &texturesLoader);

#endif