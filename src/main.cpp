#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "shader.h"
#include "renderer.h"
#include "window.h"
#include "block.h"
#include "input.h"

#include <vector>


void processInput(Input& input, Window& window);

int main() {

	std::vector<Block> blocks;

	for (int i = 0; i < 5; i++) {
		blocks.push_back({ i, i, Block::Texture::Dirt });
	}
	
	Window window;
	BlockRenderer renderer;
	Shader shader("C:/dev/2D-sandbox-engine/src/vertexShader.vs", "C:/dev/2D-sandbox-engine/src/fragmentShader.fs");
	Input input(window.m_window);

	for (Block b : blocks) {
		renderer.addBlock(b);
	}

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