#pragma once

#include <iostream>
#include <list>
#include "angle.h"
#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "satellite.h"

class Hubble : public Satellite
{
public:
	Hubble()
	{
		position = Position(0.0, -42164000.0); // always starts here
		velocity = Velocity(3100.0, 0.0); // always starts this fast in this direction
		dead = false;
		radius = 4.0; // Num of pixels
	};
	~Hubble() override;

	void draw(ogstream& gout) override { gout.drawHubble(pos, angularVelocity); }
};