//
//  projectile.h
//  Orbit
//
//  Created by Peyton Markus on 12/6/25.
//

#pragma once
#include "satellite.h"
#include "uiDraw.h"\

class Projectile : public Satellite
{
public:
   // constructor
   Projectile(const Satellite& parent, const Position& offset, const Velocity& kick)
      : Satellite(parent, offset, kick)
   {
      radius = 1.0;
      dead = false;
   }
   
   void draw(ogstream& gout) override
   {
      gout.drawProjectile(pos);
   }
   
   void move(double time) override
   {
      Satellite::move(time);
      
      if (age > 70)
      {
         dead = true;
      }
   }
};
