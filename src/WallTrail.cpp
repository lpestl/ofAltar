#include "WallTrail.h"

WallTrail::WallTrail(float height)
	: _height(height)
{
}

void WallTrail::addPoint(const glm::vec3& position) {
	_points.push_back(position);
}

void WallTrail::draw() {
	// Blue semi-transparent glowing vertical wall (height _height) between
	// each consecutive position the pawn has visited (previous -> current).
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofSetColor(0, 120, 255, 140);

	for (size_t i = 0; i + 1 < _points.size(); i++) {
		const glm::vec3& a = _points[i];
		const glm::vec3& b = _points[i + 1];

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
