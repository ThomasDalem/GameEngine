#include "systems/RenderSystem.hpp"
#include "components/Sprite.hpp"
#include "components/Collider.hpp"
#include "components/Rectangle.hpp"
#include "components/Circle.hpp"
#include "components/Line.hpp"
#include "components/Polygon.hpp"
#include "components/Position.hpp"
#include "components/Relationship.hpp"

#include <iostream>

using namespace Engine;

void drawPositions(entt::registry &reg, SDL::Renderer &renderer, const Engine::Camera &camera)
{
    auto posView = reg.view<Position>();
    posView.each([&](Position &pos){
        renderer.setDrawColor(0, 0, 255, 255);
        renderer.drawLine(Vec2f{pos.x - camera.x, pos.y - camera.y}, Vec2f{pos.x - camera.x, pos.y - 20 - camera.y});
        renderer.setDrawColor(255, 0, 0, 255);
        renderer.drawLine(Vec2f{pos.x - camera.x, pos.y - camera.y}, Vec2f{pos.x + 20 - camera.x, pos.y - camera.y});
    });
}

void drawCollider(Collider &collider, SDL::Renderer &renderer, const Engine::Camera &camera)
{
    std::vector<SDL_FPoint> points;
    for (const Vec2f &vertex : collider.vertices)
    {
        SDL_FPoint point {static_cast<float>(vertex.x - camera.x), static_cast<float>(vertex.y - camera.y)};
        points.push_back(point);
    }
    // To make a line between the first and the last vertices
    SDL_FPoint point {
        static_cast<float>(collider.vertices[collider.vertices.size() - 1].x - camera.x),
        static_cast<float>(collider.vertices[0].y - camera.y)
    };
    points.push_back(point);

    renderer.setDrawColor(255, 255, 255, 255);
    SDL_RenderDrawLinesF(renderer.getRenderer(), points.data(), collider.vertices.size() + 1);
    renderer.setDrawColor(50, 50, 50, 255);
}

void drawColliders(entt::registry &reg, SDL::Renderer &renderer, const Engine::Camera &camera)
{
    auto collidersView = reg.view<Collider>();
    collidersView.each([&](Collider &collider){
        drawCollider(collider, renderer, camera);
    });
}

void drawCircles(entt::registry &reg, SDL::Renderer &renderer, const Engine::Camera &camera)
{
    auto view = reg.view<Circle>();
    view.each([&](Circle &circle){
        if (circle.hidden == false)
        {
            renderer.drawCircle(circle.x - camera.x, circle.y - camera.y, circle.radius, circle.color);
        }
    });
}

void drawLines(entt::registry &reg, SDL::Renderer &renderer, const Engine::Camera &camera)
{
    auto view = reg.view<Line>();
    view.each([&](Line &line){
        if (line.hidden == false)
        {
            Vec2f a = line.a - camera.getPosition();
            Vec2f b = line.b - camera.getPosition();
            renderer.drawLine(a, b);
        }
    });
}

void drawPolygons(entt::registry &reg, SDL::Renderer &renderer)
{
    auto view = reg.view<Polygon>();
    view.each([&renderer](Polygon &polygon){
        renderer.drawPolygon(polygon.xs, polygon.ys, polygon.color);
    });
}

void drawSprite(Sprite &sprite, SDL_Rect &rect, SDL::Renderer &renderer, bool debug)
{
    if (sprite.hidden)
    {
        return;
    }

    if (sprite.textureRect.height == -1)
    {
        sprite.rect.width = sprite.texture->getWidth() * sprite.scale.x;
        sprite.rect.height = sprite.texture->getHeight() * sprite.scale.y;
    }
    else
    {
        sprite.rect.width = sprite.textureRect.width * sprite.scale.x;
        sprite.rect.height = sprite.textureRect.height * sprite.scale.y;
    }

    rect.w = sprite.rect.width;
    rect.h = sprite.rect.height;

    if (sprite.textureRect.width < 0 || sprite.textureRect.height < 0)
    {
        //if (sprite.center)
        //{
        //    Vec2i rotCenter = *sprite.center.get();
        //    renderer.copyEx(*sprite.texture.get(), sprite.alpha, rotCenter, sprite.angle, nullptr, &rect, sprite.flip);
        //}
        //else
        //{
        renderer.copyEx(*sprite.texture.get(), sprite.alpha, sprite.angle, nullptr, &rect, sprite.flip);
        //}
    }
    else
    {
        SDL_Rect spriteRect = {
            sprite.textureRect.x,
            sprite.textureRect.y,
            sprite.textureRect.width,
            sprite.textureRect.height
        };
        //renderer.copyEx(*sprite.texture.get(), sprite.alpha, sprite.angle, &spriteRect, &rect, sprite.flip);
        //if (sprite.center) // for rotation
        //{
        //    Vec2i rotCenter = *sprite.center.get();
        //    renderer.copyEx(*sprite.texture.get(), sprite.alpha, rotCenter, sprite.angle, &spriteRect, &rect, sprite.flip);
        //    if (debug)
        //    {
        //        const Color color = {0, 0, 255, 0};
        //        renderer.drawCircle(sprite.textureRect.x , sprite.textureRect.y, 10, color);
        //    }
        //}
        //else
        //{
        renderer.copyEx(*sprite.texture.get(), sprite.alpha, sprite.angle, &spriteRect, &rect, sprite.flip);
        //}
    }
}

void drawSpritesWithoutParent(entt::registry &reg, SDL::Renderer &renderer, const Engine::Camera &camera, bool debug)
{
    const auto view = reg.view<Sprite, Position>(entt::exclude<Parent>);

    view.each([&](Sprite &sprite, Position pos){
        SDL_Rect rect = {
            static_cast<int>(pos.x - camera.x),
            static_cast<int>(pos.y - camera.y),
            0,
            0
        };
        drawSprite(sprite, rect, renderer, debug);
    });
}

void drawSpritesWithParents(entt::registry &reg, SDL::Renderer &renderer, const Engine::Camera &camera, bool debug)
{
    const auto view = reg.view<Sprite, Position, Parent>();

    view.each([&](Sprite &sprite, Position &pos, Parent parent){
        SDL_Rect rect = {
            static_cast<int>(pos.x - camera.x),
            static_cast<int>(pos.y - camera.y),
            0,
            0
        };

        if (pos.type == ABSOLUTE)
        {
            drawSprite(sprite, rect, renderer, debug);
            return;
        }

        const Position *parentPos = reg.try_get<Position>(parent.entity);
        if (parentPos == nullptr)
        {
            drawSprite(sprite, rect, renderer, debug);
            return;
        }
        rect.x = pos.x + parentPos->x - camera.x;
        rect.y = pos.y + parentPos->y - camera.y;
        drawSprite(sprite, rect, renderer, debug);
    });
}

void updateRenderSystem(entt::registry &reg, SDL::Renderer &renderer, const Engine::Camera &camera, bool debug)
{
    drawSpritesWithParents(reg, renderer, camera, debug);
    drawSpritesWithoutParent(reg, renderer, camera, debug);

    //drawPolygons(reg, renderer);
    drawCircles(reg, renderer, camera);
    drawLines(reg, renderer, camera);
    if (debug)
    {
        drawColliders(reg, renderer, camera);
        drawPositions(reg, renderer, camera);
    }
}
