#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <STB/stb_image.h>

#include <iostream>

Texture::Texture(){}

Texture::Texture(const char* path) {

	glGenTextures(1, &m_Texture);
	glBindTexture(GL_TEXTURE_2D, m_Texture);

	stbi_set_flip_vertically_on_load(true);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int nrChannels;
	unsigned char* data = stbi_load(path, &m_TextureWidth, &m_TextureHeight, &nrChannels, 0);

	m_Rows = m_TextureHeight / m_SpriteHeight;
	m_Columns = m_TextureWidth / m_SpriteWidth;


	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_TextureWidth, m_TextureHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	stbi_image_free(data);

}

unsigned int Texture::getTexture() const {
	return m_Texture;
}

std::vector<float> Texture::returnTexCords(BlockTexture blockTexture) {
	int y = 0;
	for(int i = 0; i < m_Rows ; i++){
		int x = 0;
		for (int j = 0; j < m_Columns; j++) {
			if ((BlockTexture)(i * m_Columns + j) == blockTexture) {
				return { (float)x / m_TextureWidth,(float)y / m_TextureHeight };
			}
			x += m_SpriteWidth;
		}
		y += m_SpriteHeight;
	}
}

std::vector<float> Texture::returnSpriteSize() {
	return { (float)m_SpriteWidth / (float)m_TextureWidth, (float)m_SpriteHeight / (float)m_TextureHeight };
}

void Texture::bindTexture() {
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_Texture);
}

