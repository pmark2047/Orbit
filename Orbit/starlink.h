#pragma once

#include <iostream>
#include <list>
#include "angle.h"
#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "satellite.h"

class Starlink : public Satellite
{
public:
	Starlink()
	{
		position = Position(-0.0, -13020000.0); //starlink will always start right here
		velocity = Velocity(5800.00, 0.0); // it will have the same starting velocity
		dead = false;
		radius = 10.0; // Num of pixels
	};
	moveStarlink();
	drawStarlink();
	destroyStarlink();
};