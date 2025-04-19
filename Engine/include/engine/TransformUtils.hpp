#ifndef TRANSFORM_UTILS_HPP
#define TRANSFORM_UTILS_HPP

#include "entt.hpp"
#include "Vec.hpp"

#include "components/Position.hpp"
#include "components/Collider.hpp"
#include "components/Circle.hpp"
#include "components/Line.hpp"

void translatePos(Engine::Position &pos, const Vec2f &translation);
//void translateSprite(Engine::Sprite &sprite, const Vec2f &translation);
void translateCircle(Engine::Circle &circle, const Vec2f &translation);
void translateCollider(Engine::Collider &collider, const Vec2f &translation);
void translateLine(Engine::Line &line, const Vec2f, const Vec2f &translation);
void translate(entt::registry &reg, entt::entity e, const Vec2f &translation, bool moveChildren = true);

void setPositionPos(Engine::Position &pos, const Vec2f &newPosition);
//void setSpritePosition(Engine::Sprite &sprite, const Vec2f &position, bool centerSprite);
void setCirclePosition(Engine::Circle &circle, const Vec2f &position);
void setColliderPosition(Engine::Collider &collider, const Vec2f &position);
void setPosition(entt::registry &reg, entt::entity e, const Vec2f &position, bool centerSprites = true, bool moveChildren = true);

void rotate(entt::registry &reg, entt::entity e, float angle, bool moveChildren = true);

#endif
