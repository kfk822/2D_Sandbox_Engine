#pragma once

#include <vector>
#include <glad/glad.h>

#include "block.h"

class BlockRenderer {
private:
	unsigned int m_VBO, m_VAO, m_EBO;
	std::vector<float> m_vertices;
	std::vector<int> m_indices;
	int m_size;
public: 
	BlockRenderer();

	void addBlock(Block& block);

	void push();

	void draw();
};