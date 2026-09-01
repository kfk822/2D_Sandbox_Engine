#include "includes.h"

void processInput(Input& input, Window& window, Camera& camera, float deltaTime);

int main() {
	
	Window window("2D_Sandbox_Engine",800,600);
	Renderer renderer;
	Shader shader("src/shaders/vertexShader.vs", "src/shaders/fragmentShader.fs");
	Input input(window.m_Window);
	Camera camera(window.m_Width, window.m_Height);

	Texture texture("assets/Spritesheet.png");
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
	shader.use();
	shader.setInt("ourTexture", 0);
	shader.setMat4("projection", camera.getProjection());
	renderer.push();

	Time time;
	
	while (!window.windowShouldClose()) {
		time.calculateDeltaTime();
		processInput(input ,window, camera,time.getDeltaTime());

		shader.use();

		renderer.draw();

		shader.setMat4("view", camera.getView());
		window.update();
	}

	glfwTerminate();
	return 0;
}

void processInput(Input& input, Window& window, Camera& camera, float deltaTime) {
	if (input.isKeyPressed(Key::ESC))
		window.setShouldClose(true);
	if (input.isKeyPressed(Key::A))
		camera.move(Direction::Left, deltaTime);
	if (input.isKeyPressed(Key::D))
		camera.move(Direction::Rigth, deltaTime);
	if (input.isKeyPressed(Key::W))
		camera.move(Direction::Up, deltaTime);
	if (input.isKeyPressed(Key::S))
		camera.move(Direction::Down, deltaTime);

}