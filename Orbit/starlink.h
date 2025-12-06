#pragma once

#include <iostream>
#include <list>
#include "angle.h"
#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "satellite.h"
#include "parts.h"

class Starlink : public Satellite
{
public:
	Starlink()
	{
		pos = Position(-0.0, -13020000.0); //starlink will always start right here
		velocity = Velocity(5800.00, 0.0); // it will have the same starting velocity
		dead = false;
		radius = 10.0; // Num of pixels
	};
	~Starlink() override;
   
	void draw(ogstream& gout) override { gout.drawStarlink(pos, angularVelocity); }
   
   void destroy(list<Satellite*>& satellites) override
   {
      satellites.push_back(new StarlinkBody(*this, angle));
      satellites.push_back(new StarlinkArray(*this, angle));
   }

};
