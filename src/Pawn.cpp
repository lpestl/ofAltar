#include "Pawn.h"
#include "WallTrail.h"

Pawn::Pawn()
	: _position(0, 0, 0)
	, _direction(0, 1, 0) // Facing +Y.
	, _height(50)
	, _trail(std::make_unique<WallTrail>(_height))
{
	_trail->addPoint(_position);
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
	_trail->addPoint(_position);
}

void Pawn::turnLeft() {
	glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0, 0, 1));
	_direction = glm::vec3(rotation * glm::vec4(_direction, 0.0f));
}

void Pawn::turnRight() {
	glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(-90.0f), glm::vec3(0, 0, 1));
	_direction = glm::vec3(rotation * glm::vec4(_direction, 0.0f));
}

void Pawn::setTrail(std::unique_ptr<Trail> trail) {
	if (trail) {
		_trail = std::move(trail);
	}
}

Trail* Pawn::getTrail() const {
	return _trail.get();
}

void Pawn::draw() {
	// Vertical red line of the given height.
	ofSetColor(255, 0, 0);
	ofDrawLine(_position, _position + glm::vec3(0, 0, _height));
}

void Pawn::drawTrail() {
	_trail->draw();
}
