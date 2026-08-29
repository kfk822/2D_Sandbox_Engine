#include "window.h"

Window::Window() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(800, 600, "2D-sandbox-engine", NULL, NULL);

	glfwMakeContextCurrent(m_window);
	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return;
	}
	glViewport(0, 0, 800, 600);
}

Window::~Window() {
	glfwTerminate();
}

bool Window::windowShouldClose() {
	return glfwWindowShouldClose(m_window);
}

void Window::update() {
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}
void Window::setShouldClose(bool close) {
	glfwSetWindowShouldClose(m_window, close);
}