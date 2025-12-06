//
//  ship.h
//  Orbit
//
//  Created by Peyton Markus on 12/6/25.
//

#pragma once
#include "satellite.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "projectile.h"

class Ship : public Satellite
{
public:
   Ship()
   {
      pos.setMetersX(0.0);
      pos.setMetersY(8000000.0);
      velocity.setDX(-7000.0);
      velocity.setDY(0.0);
      radius = 10.0;
      thrusting = false;
   }
   
   void draw(ogstream& gout) override
   {
      gout.drawShip(pos, angle.getRadians(), thrusting);
   }
   
   void input(const Interface& ui, list<Satellite*>& satellites) override
   {
      thrusting = false;
      
      // Rotate Left
      if (ui.isLeft()) angle.add(-0.1);
      
      // Rotate Right
      if (ui.isRight()) angle.add(0.1);
      
      // Thrust
      if (ui.isUp())
      {
         thrusting = true;
         Acceleration acc;
         acc.set(angle, 2.0);
         velocity.add(acc, 48.0);
      }
      
      // Fire!!!
      if (ui.isSpace())
      {
         Position offset;
         offset.setPixelsX(19.0 * sin(angle.getRadians()));
         offset.setPixelsY(19.0 * cos(angle.getRadians()));
         
         Velocity kick;
         kick.set(angle, 9000.0);
         
         satellites.push_back(new Projectile(*this, offset, kick));
      }
   }
private:
   bool thrusting;
};
