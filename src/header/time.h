#pragma once

#include <glfw/glfw3.h>

class Time
{
private: 
	float deltaTime;
	float lastFrame;
public:
	Time() : deltaTime(0), lastFrame(glfwGetTime())
	{}

	float getDeltaTime() {
		return deltaTime;
	}

	void calculateDeltaTime() {
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
	}

private:

};