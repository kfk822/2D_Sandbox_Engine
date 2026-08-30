#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "shader.h"
#include "renderer.h"
#include "window.h"
#include "block.h"
#include "input.h"
#include "texture.h"

#include <vector>


void processInput(Input& input, Window& window);

int main() {
	
	Window window;
	Renderer renderer;
	Shader shader("C:/dev/2D-sandbox-engine/src/vertexShader.vs", "C:/dev/2D-sandbox-engine/src/fragmentShader.fs");
	Input input(window.m_Window);

	Texture texture("C:/dev/2D-sandbox-engine/assets/Spritesheet.png");

	std::vector<Block> blocks;
	BlockTexture blockTexture = BlockTexture::Dirt;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			blocks.push_back({ i, j, blockTexture , texture});
			blockTexture = (BlockTexture)((int)(blockTexture) + 1);
		}
	}
	for (Block b : blocks) {
		renderer.addBlock(b);
	}
	texture.bindTexture();
	shader.setInt("ourTexture", 0);
	renderer.push();

	while (!window.windowShouldClose()) {

		processInput(input ,window);

		shader.use();

		renderer.draw();

		window.update();
	}

	glfwTerminate();
	return 0;
}

void processInput(Input& input, Window& window) {
	if (input.isKeyPressed(Key::ESC))
		window.setShouldClose(true);
}