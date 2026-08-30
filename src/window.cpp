#include "window.h"

Window::Window() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(800, 600, "2D-sandbox-engine", NULL, NULL);

	glfwMakeContextCurrent(m_Window);
	glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return;
	}
	glViewport(0, 0, 800, 600);
}

Window::~Window() {
	glfwTerminate();
}

bool Window::windowShouldClose() {
	return glfwWindowShouldClose(m_Window);
}

void Window::update() {
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}
void Window::setShouldClose(bool close) {
	glfwSetWindowShouldClose(m_Window, close);
}