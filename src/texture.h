#pragma once

#include <glad/glad.h>
#include <vector>

enum class BlockTexture
{
	Dirt = 0, Grass, Sand, Snow, Mud, JungleGrass, Clay, Ice, Wood, Stone, Copper, Iron, WoodBlock, Leaves, Silver, Gold
};

class Texture {
private:
	unsigned int m_Texture;
	int m_TextureWidth, m_TextureHeight;
	const int m_SpriteWidth = 16;
	const int m_SpriteHeight = 16;

	int m_Rows, m_Columns;
public:
	Texture();
	Texture(const char* path);

	unsigned int getTexture() const;
	std::vector<float> returnTexCords(BlockTexture blockTexture);
	std::vector<float> returnSpriteSize();
	void bindTexture();
};