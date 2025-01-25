#ifndef RENDERSYSTEM_HPP
#define RENDERSYSTEM_HPP

#include "entt.hpp"
#include "SDL/Renderer.hpp"
#include "Engine/Camera.hpp"

void updateRenderSystem(entt::registry &reg, SDL::Renderer &renderer, const Engine::Camera &camera, bool debug = false);

#endif
