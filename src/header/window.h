#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	float m_Width, m_Height;
	GLFWwindow* m_Window;

	Window(const char* name,float width,float height);
	~Window();

	bool windowShouldClose();

	void update();
	void setShouldClose(bool close);

private:
	static void framebuffer_size_callback(GLFWwindow* window, int width, int heigth) {
		glViewport(0, 0, width, heigth);
	}

};

