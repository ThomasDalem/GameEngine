#include "Engine/TexturesLoader.hpp"
#include <algorithm>

TexturesLoader::TexturesLoader(SDL::Renderer &renderer) : _renderer(renderer)
{}

TexturesLoader::~TexturesLoader()
{}

std::shared_ptr<SDL::Texture> TexturesLoader::getTexture(const std::string &path)
{
    // creates the texture with these arguments if it does not exists
    auto it = _textures.try_emplace(path, std::make_shared<SDL::Texture>(path, _renderer)).first;

    return it->second;
}

SDL::Texture *TexturesLoader::getTexturePtr(const std::string &path)
{
    auto it = _textures.find(path);

    if (it == _textures.end())
    {
        return nullptr;
    }
    return it->second.get();
}
