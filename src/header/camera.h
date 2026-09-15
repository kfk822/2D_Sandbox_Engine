#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum class Direction {
	Up,
	Down,
	Left,
	Rigth,
	ZoomIn,
	ZoomOut
};

class Camera
{
private:
	float m_X, m_Y;
	float fov;
	float aspect;
	float zNear;
	float zFar;
	glm::mat4 projection;

public:
	Camera(float screenWidth, float screenHeight)  {
		m_X = 500;
		m_Y = 40;
		fov = glm::radians(45.0f);
		aspect = screenWidth / screenHeight;
		zNear = 0.1f;
		zFar = 100.0f;
		projection = glm::perspective(fov, aspect, zNear, zFar);
	}

	glm::mat4 getView() {
		return glm::lookAt(glm::vec3(m_X, m_Y, 40.0f) , glm::vec3(m_X, m_Y, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}
	glm::mat4 getProjection() {
		return projection;
	}

	void move(Direction direction, float deltaTime) {
		if (direction == Direction::Left) {
			m_X -= deltaTime * 15;
		}
		if (direction == Direction::Rigth) {
			m_X += deltaTime * 15;
		}
		if (direction == Direction::Up) {
			m_Y += deltaTime * 15;
		}
		if (direction == Direction::Down) {
			m_Y -= deltaTime * 15;
		}
	}
};