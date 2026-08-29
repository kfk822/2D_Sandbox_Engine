#pragma once

#include <vector>

class Block {
public:
	enum class Texture
	{
		Dirt = 0, Grass, Sand, Snow, Mud, JungleGrass, Clay, Ice, Wood, Stone, Copper, Iron, WoodBlock, Leaves, Silver, Gold
	};
public:
	int m_x, m_y, m_z;
	Texture m_texture;
	Block(int x, int y, Texture texture) : m_x(x), m_y(y), m_z(0), m_texture(texture)
	{}
};


