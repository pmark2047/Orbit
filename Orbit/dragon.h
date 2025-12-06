#pragma once

#include <iostream>
#include <list>
#include "angle.h"
#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "satellite.h"

class Dragon : public Satellite
{
public:
	Dragon()
	{
		pos = Position(0.0, -8000000.0); // always starts here
		velocity = Velocity(7900.0, 0.0); // always starts this fast in this direction
		dead = false;
		radius = 7.0; // Num of pixels
	};
	~Dragon() override;

	void draw(ogstream& gout) override { gout.drawCrewDragon(pos, angularVelocity); }
   
};
