#pragma once

#include <vector>
#include "texture.h"

class Block {
public:

public:

	int m_X, m_Y;
	float m_Texturex, m_Texturey;
	float m_TextureHeight, m_TextureWidth;
	Block(int x, int y, BlockTexture blockTexture,Texture& texture)
	{
		m_X = x;
		m_Y = y;
		std::vector<float> texCoords = texture.returnTexCords(blockTexture);
		m_Texturex = texCoords[0];
		m_Texturey = texCoords[1];
		std::vector<float> spriteSize = texture.returnSpriteSize();
		m_TextureWidth = spriteSize[0];
		m_TextureHeight = spriteSize[1];
	}
};


