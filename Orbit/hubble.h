#pragma once

#include <iostream>
#include <list>
#include "angle.h"
#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "satellite.h"
#include "parts.h"

class Hubble : public Satellite
{
public:
	Hubble()
	{
		pos = Position(0.0, -42164000.0); // always starts here
		velocity = Velocity(3100.0, 0.0); // always starts this fast in this direction
		dead = false;
		radius = 4.0; // Num of pixels
	};
	~Hubble() override;

	void draw(ogstream& gout) override { gout.drawHubble(pos, angularVelocity); }
   
   void destroy(list<Satellite*>& satellites) override
   {
      satellites.push_back(new HubbleLeft(*this, angle));
      satellites.push_back(new HubbleRight(*this, angle));
      satellites.push_back(new HubbleComputer(*this, angle));
      satellites.push_back(new HubbleTelescope(*this, angle));
   }
};
