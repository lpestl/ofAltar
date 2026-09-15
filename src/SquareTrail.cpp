#include "SquareTrail.h"

SquareTrail::SquareTrail(float halfSize)
	: _halfSize(halfSize)
{
}

void SquareTrail::addPoint(const glm::vec3& position) {
	_points.push_back(position);
}

void SquareTrail::draw() {
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofSetColor(0, 120, 255, 140);

	const float h = _halfSize;
	for (const glm::vec3& p : _points) {
		// A square in the X/Y plane, centered on the visited position.
		ofMesh quad;
		quad.setMode(OF_PRIMITIVE_TRIANGLES);
		quad.addVertex(glm::vec3(p.x - h, p.y - h, p.z));
		quad.addVertex(glm::vec3(p.x + h, p.y - h, p.z));
		quad.addVertex(glm::vec3(p.x + h, p.y + h, p.z));
		quad.addVertex(glm::vec3(p.x - h, p.y + h, p.z));
		quad.addIndex(0);
		quad.addIndex(1);
		quad.addIndex(2);
		quad.addIndex(0);
		quad.addIndex(2);
		quad.addIndex(3);
		quad.draw();
	}

	ofDisableBlendMode();
}
