#pragma once

#include "Trail.h"
#include <vector>

// Alternative trail: horizontal squares lying in the X/Y plane, each centered
// on a position visited by the pawn.
class SquareTrail : public Trail {
public:
	explicit SquareTrail(float halfSize = 25.0f);

	void addPoint(const glm::vec3& position) override;
	void draw() override;

private:
	float _halfSize;
	std::vector<glm::vec3> _points;
};
