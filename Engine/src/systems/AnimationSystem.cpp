#include <iostream>
#include "systems/AnimationSystem.hpp"
#include "components/Animation.hpp"
#include "components/Sprite.hpp"
#include <SDL2/SDL_timer.h>

using namespace Engine;

void animateSprites(entt::registry &reg, float time)
{
    auto view = reg.view<Animation, Sprite>();

    view.each([time](Animation &anim, Sprite &sprite){
        if (anim.playAnim == false || anim.steps == 0)
        {
            return;
        }
        if (anim.curStep >= anim.steps - 1)
        {
            anim.curStep = 0;
            anim.startTime = time;
        }

        const int currentStep = (SDL_GetTicks64() / anim.duration) % anim.steps;
        sprite.textureRect.x = anim.spriteSize.x * currentStep;
        sprite.textureRect.y = anim.startPos.y;
        sprite.textureRect.height = anim.spriteSize.y;
        sprite.textureRect.width = anim.spriteSize.x;
        anim.curStep = currentStep;
    });
}
