/***********************************************************************
 * Source File:
 *    SATELLITE
 * Author:
 *    Peyton and Jackson
 * Summary:
 *    The things in space
 ************************************************************************/

#include "satellite.h"

using namespace std;

/********************************************************
 * SATELLITE
 * Create a Satellite (called by the derived classes)
 *******************************************************/
Satellite::Satellite(const Satellite& parent, const Angle & direction) :
   velocity(parent.velocity),
   pos(parent.pos),
   angle(parent.angle),
   angularVelocity(parent.angularVelocity),
   radius(0.0),
   age(0),
#ifndef NDEBUG
   useRandom(parent.useRandom),
#endif
   dead(false)
{
   // compute the kick
   double speed = random(1000.0, 3000.0);
#ifndef NDEBUG
   if (parent.useRandom == false)
      speed = 3000.0;
#endif // DEBUG
   Velocity kick(direction, speed);
   velocity += kick;
   
   // compute the offset
   Position posKick;
   posKick.setPixelsX(4.0 * sin(direction.getRadians()));
   posKick.setPixelsY(4.0 * cos(direction.getRadians()));
   pos.addMetersX(posKick.getMetersX());
   pos.addMetersY(posKick.getMetersY());
}

