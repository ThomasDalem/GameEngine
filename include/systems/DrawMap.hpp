#ifndef DRAW_MAP_HPP
#define DRAW_MAP_HPP

#include "entt.hpp"
#include "SDL/Renderer.hpp"
#include "Engine.hpp"

void drawMap(entt::registry &reg, SDL::Renderer &renderer, const Engine::Camera &camera);

#endif