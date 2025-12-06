#pragma once

#include <iostream>
#include <list>
#include "angle.h"
#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "satellite.h"
#include "parts.h"

class GPS : public Satellite
{
public:
   GPS()
   {
      pos = Position(0.0, 26560000.0);
      velocity = Velocity(-3880.0, 0.0);
      dead = false;
      radius = 12;
   }
	GPS(Position pos, Velocity velocity)
	{
		this->pos = pos;
		this->velocity = velocity;
		dead = false;
	};
   ~GPS() override { };

	void draw(ogstream& gout) override { gout.drawGPS(pos, angularVelocity); }
   
   void destroy(list<Satellite*>& satellites) override
   {
      satellites.push_back(new GPSCenter(*this, angle));
      satellites.push_back(new GPSLeft(*this, angle));
      satellites.push_back(new GPSRight(*this, angle));
   }
};
