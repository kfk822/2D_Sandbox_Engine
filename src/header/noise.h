#pragma once

#include <cstdlib>
#include <vector>
#include <cmath>

class Noise {
public:

private:
	std::vector<float> m_grid;
public:
	Noise(unsigned int seed, int width) {
		srand(seed);
		int grid_length = width / 10;
		grid_length++;
		m_grid.reserve(grid_length);
		for (int i = 0; i < grid_length; i++) {
			m_grid.emplace_back((double)rand() / RAND_MAX);
		}

	}

	float getNoiseValue(float location) {
		int gridBottom = std::floor(location);
		int gridTop = std::ceil(location);

		float gridPlace = location - gridBottom;

		return m_grid[gridTop] * gridPlace + m_grid[gridBottom] * (1.0f - gridPlace);
	}
};