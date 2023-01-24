#pragma once
#include "Tile.h"
#include <map>
#include <unordered_map>

class TileMap
{
public:
	TileMap(const int world_width, const int world_height);

	void loadTexture(const std::string texture_id, const std::string texture_path);
	sf::Vector2i toTileCoords(const sf::Vector2i position);

	void setWorldSize(const int world_width, const int world_height);
	sf::Vector2i getWorldSize() const;

	void generateWorld();

private:
	std::unordered_map<std::string, sf::Texture> m_textures;
	sf::Vector2f m_tile_sizes;

	int m_world_width;
	int m_world_height;
};

