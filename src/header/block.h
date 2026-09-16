#pragma once

#include <vector>
#include "../header/texture.h"
#include "blockTexture.h"

class Block {
public:

public:
	float m_Texturex, m_Texturey;
	float m_TextureHeight, m_TextureWidth;
	Block() {}
	Block(BlockTexture blockTexture,Texture& texture)
	{
		std::vector<float> texCoords = texture.returnTexCords(blockTexture);
		m_Texturex = texCoords[0];
		m_Texturey = texCoords[1];
		std::vector<float> spriteSize = texture.returnSpriteSize();
		m_TextureWidth = spriteSize[0];
		m_TextureHeight = spriteSize[1];
	}
};


