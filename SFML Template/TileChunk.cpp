#include "TileChunk.h"

TileChunk::TileChunk(const int chunk_x, const int chunk_y, 
                     const int chunk_width, const int chunk_height)
{
    m_handler_ptr = nullptr;
    m_tiles = nullptr;

    m_chunk_location = sf::Vector2i(chunk_x, chunk_y);
    m_chunk_size = sf::Vector2i(chunk_width, chunk_height);
}

void TileChunk::setTextureHandler(TextureHandler* texture_handler)
{
    m_handler_ptr = texture_handler;
}

sf::Vector2i TileChunk::getChunkLocation() const
{
    return m_chunk_location;
}

sf::Vector2i TileChunk::getChunkSize() const
{
    return m_chunk_size;
}

Tile* TileChunk::getTile(const int x, const int y) const
{
    if (m_tiles != nullptr)
        return m_tiles[x][y];
    else
        return nullptr;
}

void TileChunk::setTile(const int x, const int y, Tile* tile)
{
    deleteTile(x, y);
    m_tiles[x][y] = tile;
}

void TileChunk::deleteTile(const int x, const int y)
{
    if (m_tiles[x][y] != nullptr)
        delete m_tiles[x][y];
}

void TileChunk::draw(sf::RenderTarget& target, sf::RenderStates& states)
{
    for (int x = 0; x < m_chunk_size.x; x++)
        for (int y = 0; y < m_chunk_size.y; y++)
        {
            m_tiles[x][y]->draw(target, states);
        }
}
