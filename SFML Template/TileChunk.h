#pragma once
#include "TextureHandler.h"
#include "Tile.h"

class TileChunk
{
public:
	TileChunk(const int chunk_x, const int chunk_y, 
			  const int chunk_width, const int chunk_height);

	void setTextureHandler(TextureHandler* texture_handler);

	sf::Vector2i getChunkLocation() const;
	sf::Vector2i getChunkSize() const;
	Tile* getTile(const int x, const int y) const;
	void setTile(const int x, const int y, Tile* tile);
	void deleteTile(const int x, const int y);

	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates& states);
private:
	sf::Vector2i m_chunk_location;
	sf::Vector2i m_chunk_size;

	TextureHandler* m_handler_ptr;
	Tile*** m_tiles;
};

