#include "utils/TransformUtils.hpp"
#include "components/Relationship.hpp"

using namespace Engine;

void translatePos(Position &pos, const Vec2f &translation)
{
    pos += translation;
}

void translateSprite(Sprite &sprite, const Vec2f &translation)
{
    sprite.rect.x += translation.x;
    sprite.rect.y += translation.y;
}

void translateCircle(Circle &circle, const Vec2f &translation)
{
    circle.x += translation.x;
    circle.y += translation.y;
}

void translateCollider(Collider &collider, const Vec2f &translation)
{
    for (Vec2f &vertex : collider.vertices)
    {
        vertex += translation;
    }
}

void translateLine(Line &line, const Vec2f &translation)
{
    line.a += translation;
    line.b += translation;
}

void translate(entt::registry &reg, entt::entity e, const Vec2f &translation, bool moveChildren)
{
    Position &pos = reg.get<Position>(e);
    if (pos.type == ABSOLUTE)
    {
        translatePos(pos, translation);
    }

    Sprite *sprite = reg.try_get<Sprite>(e);
    if (sprite != nullptr && pos.type == ABSOLUTE)
    {
        translateSprite(*sprite, translation);
    }

    Collider *collider = reg.try_get<Collider>(e);
    if (collider != nullptr)
    {
        translateCollider(*collider, translation);
    }

    Circle *circle = reg.try_get<Circle>(e);
    if (circle != nullptr)
    {
        translateCircle(*circle, translation);
    }

    Line *line = reg.try_get<Line>(e);
    if (line != nullptr)
    {
        translateLine(*line, translation);
    }

    if (moveChildren == false)
    {
        return;
    }

    // TODO: maybe change to use children
    auto view = reg.view<Parent>();

    for (const entt::entity child : view)
    {
        const Parent &parent = reg.get<Parent>(child);
        if (parent.entity == e)
        {
            translate(reg, child, translation, true);
        }
    }
}


void setPositionPos(Position &pos, const Vec2f &newPosition)
{
    pos = newPosition;
}

void setSpritePosition(Sprite &sprite, const Vec2f &position, bool centerSprite)
{
    sprite.rect.x = position.x;
    sprite.rect.y = position.y;
    if (centerSprite)
    {
        const Vec2i &center = sprite.texture->getCenter();
        sprite.rect.x -= center.x;
        sprite.rect.y -= center.y;
    }
}

void setCirclePosition(Circle &circle, const Vec2f &position)
{
    circle.x = position.x;
    circle.y = position.y;
}

void setColliderPosition(Collider &collider, const Vec2f &position)
{
    for (Vec2f &vertex : collider.vertices)
    {
        vertex = position;
    }
}

void setPosition(entt::registry &reg, entt::entity e, const Vec2f &position, bool centerSprites, bool moveChildren)
{
    Position *pos = reg.try_get<Position>(e);
    if (pos != nullptr)
    {
        translatePos(*pos, position);
    }

    Sprite *sprite = reg.try_get<Sprite>(e);
    if (sprite != nullptr)
    {
        setSpritePosition(*sprite, position, centerSprites);
    }

    Collider *collider = reg.try_get<Collider>(e);
    if (collider != nullptr)
    {
        setColliderPosition(*collider, position);
    }

    Circle *circle = reg.try_get<Circle>(e);
    if (circle != nullptr)
    {
        setCirclePosition(*circle, position);
    }

    if (moveChildren == false)
    {
        return;
    }

    const auto view = reg.view<Parent>();

    for (const entt::entity child : view)
    {
        const Parent &parent = reg.get<Parent>(child);
        if (parent.entity == e)
        {
            setPosition(reg, child, position, true);
        }
    }
}

void rotateSprite(entt::registry &reg, entt::entity e, Sprite &sprite, float angle)
{
    Parent *parent = reg.try_get<Parent>(e);
    if (parent)
    {
        Sprite *parentSprite = reg.try_get<Sprite>(parent->entity);
        if (parentSprite)
        {
            //sprite.center = parentSprite->center;
        }
    }
    sprite.angle = angle;
}

void rotate(entt::registry &reg, entt::entity e, float angle, bool moveChildren)
{
    Sprite *sprite = reg.try_get<Sprite>(e);
    if (sprite != nullptr)
    {
        rotateSprite(reg, e, *sprite, angle);
    }

/*     Collider *collider = reg.try_get<Collider>(e);
    if (collider != nullptr)
    {
        translateCollider(*collider, translation);
    }
*/

    if (moveChildren == false)
    {
        return;
    }

    auto view = reg.view<Parent>();

    for (const entt::entity child : view)
    {
        const Parent &parent = reg.get<Parent>(child);
        if (parent.entity == e)
        {
            rotate(reg, child, angle, true);
        }
    }
}
