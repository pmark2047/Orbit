/***********************************************************************
 * Header File:
 *    SATELLITE
 * Author:
 *    Peyton and Jackson
 * Summary:
 *    The things in space
 ************************************************************************/

#pragma once

#include <iostream>
#include <list>
#include "angle.h"
#include "position.h"
#include "velocity.h"
#include "uiDraw.h"
#include "physics.hpp"
#include "uiInteract.h"

class Interface; // forward declaration

enum SatellitesType
{
   SHIP,
   GPS_WHOLE, GPS_LEFT, GPS_RIGHT, GPS_CENTER,
   HUBBLE, HUBBLE_LEFT, HUBBLE_RIGHT, HUBBLE_COMPUTER, HUBBLE_CENTER,
   STARLINK, STARLINK_BODY, STARLINK_ARRAY,
   SPUTNIK,
   CREWDRAGON,
   FRAGMENT
};


class Satellite
{
   public:
      //friend TestSatellite
      
      //
      // constructors
      //
   
      // !!!!!! temp constructor !!!!!!
      Satellite(const Position & pos, const Velocity & vel);
      
      // Earth needs a default constructor
      Satellite(int age = 0, double radius = 0.0, double angularVelocity = 0.0)
      : angularVelocity(angularVelocity), dead(false), age(age), radius(radius)
      {
#ifndef NDEBUG
      useRandom = true;
#endif // DEBUG
      }
      
      // Used to create parts and fragments
      Satellite(const Satellite& parent, const Angle & direction);
      
      // Used to create projectiles. they have specific speeds
      Satellite(const Satellite& parent, const Position & offset, const Velocity & kick);
      
      //
      // Getters
      //
      
      // Return the radius of the Satellite in Meters
      double getRadius() const { return radius; }
      
      // Return whether we are dead
      bool isDead() const { return dead; }
      
      // This has got to go
      bool isInvisible() const { return age < 10; }
      
      // Where are we pointed
      const Angle& getAngle() const { return angle; }
      
      // Where are we located
      const Position& getPosition() const { return pos; }
      
      //
      // Setters
      //
      
      virtual void kill() { if (!isInvisible()) dead = true;}
   
      //
      // Stuff to be Overridden
      //
      
      virtual bool getDefunct() { return false; }
      
      // Draw an item on the screen
      virtual void draw(ogstream &gout) { gout.drawSputnik(pos, angularVelocity); }
      
      // Kill this element
      virtual void destroy(std::list <Satellite*>& satellites) {}
      
      // Advance the item by (time dialation) seconds
      virtual void move(double time);
      
      // Handle input
      virtual void input(const Interface& ui, std::list <Satellite*>& satellites) {}
   
   protected:
      Velocity    velocity;
      Position    pos;
      Angle       angle;
      double      angularVelocity;
      bool        dead;
      double      radius;
      int         age;
#ifndef NDEBUG
      bool        useRandom;
#endif // DEBUG
};
