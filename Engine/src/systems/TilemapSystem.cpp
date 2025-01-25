#include "systems/TilemapSystem.hpp"

#include "components/Tilemap.hpp"

using namespace Engine;

void drawMap(entt::registry &reg, SDL::Renderer &renderer, const Engine::Camera &camera)
{
    const auto view = reg.view<Tilemap>();

    for (const entt::entity e : view)
    {
        Tilemap &tilemap = reg.get<Tilemap>(e);

        for (std::size_t y = 0; y < tilemap.y; y++)
        {
            for (std::size_t x = 0; x < tilemap.x; x++)
            {
                const TileType tiletype = tilemap.map[y * tilemap.y + x];
                if (tiletype == TileType::EMPTY)
                {
                    continue;
                }
                else if (tiletype == TileType::ROAD)
                {
                    const Vec2i &tilePos = TILES_POS[TileType::ROAD];
                    const SDL_Rect src = {tilePos.x, tilePos.y, tilemap.tileWidth, tilemap.tileHeight};
                    const SDL_Rect dst = {
                        static_cast<int>(x * tilemap.tileWidth * 3) - camera.getPosition().x,
                        static_cast<int>(y * tilemap.tileWidth * 3) - camera.getPosition().y,
                        tilemap.tileWidth * 3,
                        tilemap.tileHeight * 3};

                    renderer.copy(*tilemap.texture.get(), &src, &dst);
                }
            }
        }
    }
}
