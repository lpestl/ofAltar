#pragma once

#include "ofMain.h"

// Abstract trail component that can be attached to a Pawn and overridden with
// different visualizations (e.g. vertical walls or horizontal squares).
class Trail {
public:
	virtual ~Trail() {}

	// Record a new position visited by the pawn.
	virtual void addPoint(const glm::vec3& position) = 0;

	// Render the trail.
	virtual void draw() = 0;
};
