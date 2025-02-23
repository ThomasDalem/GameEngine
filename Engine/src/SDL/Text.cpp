#include "Text.hpp"
#include "Font.hpp"

using namespace SDL;

Text::Text(const std::string &text, SDL::Renderer &renderer, int fontSize) 
    : _text(text)
    , _renderer(renderer)
    , _fontSize(fontSize)
{
    SDL::Font &font = HUD::Font::getInstance().getFont();

    if (font.isLoaded() == false)
    {
        font.loadFont("../assets/font.ttf", _fontSize);
    }
    if (font.getSize() != _fontSize)
    {
        font.setSize(_fontSize);
    }
    _surface = TTF_RenderText_Solid(font.getFont(), text.c_str(), {255, 255, 255, 255});
    _texture.loadFromSurface(_surface, renderer);
}

void Text::setText(const std::string &text)
{
    _text = text;
    SDL::Font &font = HUD::Font::getInstance().getFont();
    
    if (font.isLoaded() == false)
    {
        font.loadFont("../assets/font.ttf", _fontSize);
    }
    if (font.getSize() != _fontSize)
    {
        font.setSize(_fontSize);
    }
    _surface = TTF_RenderText_Solid(font.getFont(), _text.c_str(), {255, 255, 255, 255});
    _texture.loadFromSurface(_surface, _renderer);
}

const std::string &Text::getText() const
{
    return _text;
}

Texture &Text::getTexture()
{
    return _texture;
}

int Text::getFontSize() const
{
    return _fontSize;
}
