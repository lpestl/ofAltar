#include "Pawn.h"

Pawn::Pawn()
	: _position(0, 0, 0)
	, _direction(0, 1, 0) // Facing +Y.
	, _height(50)
{
	_trail.push_back(_position);
}

void Pawn::setPosition(const glm::vec3& position) {
	_position = position;
}

glm::vec3 Pawn::getPosition() const {
	return _position;
}

void Pawn::setDirection(const glm::vec3& direction) {
	_direction = glm::normalize(direction);
}

glm::vec3 Pawn::getDirection() const {
	return _direction;
}

void Pawn::moveForward(float distance) {
	_position += _direction * distance;
	_trail.push_back(_position);
}

void Pawn::turnLeft() {
	glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0, 0, 1));
	_direction = glm::vec3(rotation * glm::vec4(_direction, 0.0f));
}

void Pawn::turnRight() {
	glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(-90.0f), glm::vec3(0, 0, 1));
	_direction = glm::vec3(rotation * glm::vec4(_direction, 0.0f));
}

void Pawn::draw() {
	// Vertical red line of the given height.
	ofSetColor(255, 0, 0);
	ofDrawLine(_position, _position + glm::vec3(0, 0, _height));
}

void Pawn::drawTrail() {
	// Blue semi-transparent glowing vertical wall (height 50) between each
	// consecutive position the pawn has visited (previous -> current).
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofSetColor(0, 120, 255, 140);

	for (size_t i = 0; i + 1 < _trail.size(); i++) {
		const glm::vec3& a = _trail[i];
		const glm::vec3& b = _trail[i + 1];

		ofMesh poly;
		poly.setMode(OF_PRIMITIVE_TRIANGLES);
		poly.addVertex(glm::vec3(a.x, a.y, 0));
		poly.addVertex(glm::vec3(b.x, b.y, 0));
		poly.addVertex(glm::vec3(b.x, b.y, _height));
		poly.addVertex(glm::vec3(a.x, a.y, _height));
		poly.addIndex(0);
		poly.addIndex(1);
		poly.addIndex(2);
		poly.addIndex(0);
		poly.addIndex(2);
		poly.addIndex(3);
		poly.draw();
	}

	ofDisableBlendMode();
}
