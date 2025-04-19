#include "engine/WinInfo.hpp"
#include <SDL2/SDL_mouse.h>

WinInfo::WinInfo() : _app(nullptr), _mousePos(0, 0)
{}

Vec2i WinInfo::getMousePos() const
{
    Vec2i pos;
    SDL_GetMouseState(&pos.x, &pos.y);
    return pos;
}

Vec2i WinInfo::getScaledMousePos() const
{
    /* Vec2i pos;
    SDL_GetMouseState(&pos.x, &pos.y);
    Vec2i winSize;
    SDL_GetWindowSize(_app->getWindow(), &winSize.x, &winSize.y);
    Vec2i logicalSize;
    SDL_RenderGetLogicalSize(_app->getRenderer().getRenderer(), &logicalSize.x, &logicalSize.y);

    pos.x /= static_cast<float>(winSize.x) / static_cast<float>(logicalSize.x);
    pos.y /= static_cast<float>(winSize.y) / static_cast<float>(logicalSize.y);

    return pos; */
    return _mousePos;
}

Vec2i WinInfo::getWinSize() const
{
    return _winSize;
}

void WinInfo::setApp(SDL::App *app)
{
    _app = app;
}

void WinInfo::setWindowSize(const Vec2i &size)
{
    _winSize = size;
}

void WinInfo::setMousePos(int x, int y)
{
    _mousePos.x = x;
    _mousePos.y = y;
}
