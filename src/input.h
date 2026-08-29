#pragma once
#include <glfw/glfw3.h>

enum class Key {
	W = GLFW_KEY_W,
	A = GLFW_KEY_A,
	S = GLFW_KEY_S,
	D = GLFW_KEY_D,
	ESC = GLFW_KEY_ESCAPE,
	E = GLFW_KEY_E,
	F = GLFW_KEY_F,
	Q = GLFW_KEY_Q,

};

class Input {
private:
	GLFWwindow* m_window;
public:
	Input(GLFWwindow* window) : m_window(window){}

	void update();

	bool isKeyPressed(Key key) {
		return glfwGetKey(m_window, (int)key) == GLFW_PRESS;
	}
	bool isKeyReleased(Key key) {
		return glfwGetKey(m_window, (int)key) == GLFW_RELEASE;
	}

};