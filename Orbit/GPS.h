#pragma once

#include <iostream>
#include <list>
#include "angle.h"
#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "satellite.h"

class GPS : public Satellite
{
	GPS(Position pos, Velocity velocity)
	{
		this->pos = pos;
		this->velocity = velocity;
		dead = false;
	};
};