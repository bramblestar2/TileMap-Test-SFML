#pragma once
#include "TextureHandler.h"
#include "Tile.h"

class TileChunk
{
public:
	TileChunk(const int chunk_x, const int chunk_y, const int chunk_width, const int chunk_height);

	sf::Vector2i getChunkLocation() const;
	sf::Vector2i getChunkSize() const;

	void draw(sf::RenderTarget& target, sf::RenderStates& states);
private:
	sf::Vector2i m_chunk_location;
	sf::Vector2i m_chunk_size;

	TextureHandler* m_handler_ptr;
};

