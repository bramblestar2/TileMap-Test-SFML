#include "TileChunk.h"

sf::Vector2i TileChunk::getChunkLocation() const
{
    return m_chunk_location;
}

sf::Vector2i TileChunk::getChunkSize() const
{
    return m_chunk_size;
}
