#include "systems/MovementSystem.hpp"

#include "Engine/TransformUtils.hpp"
#include "components/Movement.hpp"

using namespace Engine;

void moveObjects(entt::registry &reg, float deltaTime)
{
    const auto view = reg.view<Movement, Position>();

    for (const entt::entity e : view)
    {
        const Movement &mov = reg.get<Movement>(e);

        if (mov.move == false)
        {
            continue;
        }
        const Vec2f posDelta = mov.direction * mov.speed * deltaTime;
        translate(reg, e, posDelta);
    }
}
