#include "TileMap.h"
#include <iostream>

void TileMap::loadTexture(const std::string texture_id, const std::string texture_path)
{

	sf::Texture tex;
	if (tex.loadFromFile(texture_path))
	{
		m_textures[texture_id] = tex;
	}
	else
	{
		std::cout << "There was an error loading texture: " << texture_id << std::endl;;
	}
}

sf::Vector2i TileMap::toTileCoords(const sf::Vector2i position)
{
	return sf::Vector2i(position.x / m_tile_sizes.x, position.y / m_tile_sizes.y);
}

void TileMap::setWorldSize(const int world_width, const int world_height)
{
	m_world_width = world_width;
	m_world_height = world_height;
}

sf::Vector2i TileMap::getWorldSize() const
{
	return sf::Vector2i(m_world_width, m_world_height);
}
