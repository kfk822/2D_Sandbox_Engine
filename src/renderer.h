#pragma once

#include <vector>
#include <glad/glad.h>

#include "block.h"

class Renderer {
private:
	unsigned int m_VBO, m_VAO, m_EBO;
	std::vector<float> m_Vertices;
	std::vector<int> m_Indices;
	int m_Size;
public: 
	Renderer();

	void addBlock(Block& block);

	void push();

	void draw();
};