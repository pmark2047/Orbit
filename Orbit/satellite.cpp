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

// Temporary Constructor
Satellite::Satellite(const Position & pos, const Velocity & vel) :
   pos(pos),
   velocity(vel),
   radius(10.0),
   dead(false),
   age(0),
   angularVelocity(0.0)
{ }

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

Satellite::Satellite(const Satellite& parent, const Position& offset, const Velocity& kick) :
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
   // new velocity is the velocity of your parent plus the direction of the kick
   velocity += kick;
   // advance by one time unit so we do not hit our parent
   pos.addMetersX(offset.getMetersX());
   pos.addMetersY(offset.getMetersY());
}

/********************************************************
 * SATELLITE :: MOVE
 * Inertia and graviry and stuff
 *******************************************************/
void Satellite::move(double time)
{
   // gravity and inertia
   Acceleration aGravity = getGravity(pos);
   this->velocity.add(aGravity, time / 2.0);
   this->pos.add(aGravity, velocity, time);
   this->velocity.add(aGravity, time / 2.0);
   
   // rotational inertia
   this->angle.add(angularVelocity);
   
   // increase the age
   this->age++;
}

/*
********************************************************
 * PROJECTILE :: MOVE
 * Projectiles die
 *******************************************************
void Projectile::move(double timeDialation)
{
   Satellite::move(timeDialation);
   // a bullet dies after it has lived for 100 frames
   if (this->age > 100)
      this->dead == true;
}
*/ // ^^^^^^^^ COMMENT OUT FOR NOW ^^^^^^^^^
