#pragma once

#include "ofMain.h"
#include <vector>

// A player entity that moves on the X/Y plane (up = Z axis).
class Pawn {
public:
	Pawn();

	void setPosition(const glm::vec3& position);
	glm::vec3 getPosition() const;

	void setDirection(const glm::vec3& direction);
	glm::vec3 getDirection() const;

	// Move forward along the current direction by the given distance.
	void moveForward(float distance);

	// Rotate the direction by 90 degrees around the vertical (Z) axis.
	void turnLeft();
	void turnRight();

	void draw();
	void drawTrail();

private:
	glm::vec3 _position;
	glm::vec3 _direction; // Unit vector on the X/Y plane.
	float _height;
	std::vector<glm::vec3> _trail; // Positions the pawn has visited.
};
