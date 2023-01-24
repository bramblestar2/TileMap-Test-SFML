#pragma once
#include "TileChunk.h"
#include <map>

class ChunkManager
{
public:
	ChunkManager();
	~ChunkManager();

	bool loadChunk(const int x, const int y);
	bool unloadChunk(const int x, const int y);
	bool saveChunk(const int x, const int y);
	TileChunk* getChunk(const int x, const int y);

private:
	std::map<int, std::map<int, TileChunk>> m_chunks;

};

