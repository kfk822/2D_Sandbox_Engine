#pragma once

#include "noise.h"
#include <vector>
#include <unordered_map>
#include "blockTexture.h"
#include "block.h"

class WorldHandler {
private:
	std::vector<BlockTexture> m_world;
	std::unordered_map<BlockTexture, Block> m_blocklist;
	int m_width, m_height;
	int m_Horizon;
public:
	WorldHandler(int width, int height, int blockTypeCount) {
		m_world.resize(width * height);
		m_blocklist.reserve(blockTypeCount);
		m_width = width;
		m_height = height;
		m_Horizon = 20;
	}

	void addBlock(Block& block, BlockTexture texture) {
		m_blocklist.emplace(texture, block);
	}

	void generateWorld(int seed) {
		Noise noise(seed, m_width);
		float location = 0.0f;
		for (int i = 0; i < m_width; i++) {
			int horizon = m_Horizon + 20 * noise.getNoiseValue(location);
			location += 0.025f;
			for (int j = 0; j < m_height; j++) {
				if (j == horizon)
					m_world[i * m_width + j] = BlockTexture::Grass;
				else if(j > horizon -5 && j< horizon)
					m_world[i * m_width + j] = BlockTexture::Dirt;
				else if (j < horizon)
					m_world[i * m_width + j] = BlockTexture::Stone;
				else
					m_world[i * m_width + j] = BlockTexture::Air;
			}
		}
	}

	Block getBlockType(BlockTexture texture) {
		return m_blocklist[texture];
	}
	BlockTexture getBlock(int x, int y) {
		return m_world[x * m_width + y];
	}
};