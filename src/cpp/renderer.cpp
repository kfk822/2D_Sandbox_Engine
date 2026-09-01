#include "../header/renderer.h"

Renderer::Renderer() {
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);
	m_Size = 0;
}

void Renderer::addBlock(Block& block) {
	float x = block.m_X;
	float y = block.m_Y;
	float textureX = block.m_Texturex;
	float textureY = block.m_Texturey;
	float textureWidth = block.m_TextureWidth;
	float textureHeight = block.m_TextureHeight;

	std::vector<float> vertices = {
		x, y, textureX, textureY,
		x, y + 1, textureX, textureY + textureHeight,
		x + 1, y + 1,textureX + textureWidth, textureY + textureHeight,
		x + 1, y,textureX + textureWidth, textureY
	};
	int size = m_Vertices.size() / 4;
	std::vector<int> indices = {
		size, size + 1, size + 3,
		size + 1, size + 2, size + 3
	};

	m_Vertices.insert(m_Vertices.end(), vertices.begin(), vertices.end());
	m_Indices.insert(m_Indices.end(), indices.begin(), indices.end());

}

void Renderer::push() {
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(float), m_Vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(int), m_Indices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void Renderer::draw() {
	glClearColor(0.0f, 0.6f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, m_Indices.size(), GL_UNSIGNED_INT, 0);
}