#pragma once

#include <iostream>
#include <list>
#include "angle.h"
#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "satellite.h"

class Sputnik : public Satellite
{
public:
	Sputnik() 
	{
		position = Position(-36515095.13, 21082000.0); // always starts here
		velocity = Velocity(2050.0, 2684.68); // always starts this fast in this direction
		dead = false;
		radius = 4.0; // Num of pixels
	};
	moveSputnik();
	drawSputnik();
	destroySputnik();
};