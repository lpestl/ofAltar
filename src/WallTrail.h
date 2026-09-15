#pragma once

#include "Trail.h"
#include <vector>

// Default trail: blue semi-transparent glowing vertical walls between
// consecutive positions visited by the pawn.
class WallTrail : public Trail {
public:
	explicit WallTrail(float height = 50.0f);

	void addPoint(const glm::vec3& position) override;
	void draw() override;

private:
	float _height;
	std::vector<glm::vec3> _points;
};
