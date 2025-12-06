#pragma once

#include <iostream>
#include "uiDraw.h"
#include "satellite.h"

/**************************
 * GPS LEFT
 * Part
**************************/
class GPSLeft : public Satellite
{
public:
   // constructor
   GPSLeft(const Satellite& parent, const Angle& direction) : Satellite(parent, direction)
   {
      radius = 8.0;
   }
   
   void draw(ogstream& gout) override
   {
      gout.drawGPSLeft(pos, angle.getRadians());
   }
};

/**************************
 * GPS RIGHT
 * Part
**************************/
class GPSRight : public Satellite
{
public:
   // constructor
   GPSRight(const Satellite& parent, const Angle& direction) : Satellite(parent, direction)
   {
      radius = 8.0;
   }
   
   void draw(ogstream& gout) override
   {
      gout.drawGPSRight(pos, angle.getRadians());
   }
};

/**************************
 * GPS CENTER
 * Part
**************************/
class GPSCenter : public Satellite
{
public:
   // constructor
   GPSCenter(const Satellite& parent, const Angle& direction) : Satellite(parent, direction)
   {
      radius = 8.0;
   }
   
   void draw(ogstream& gout) override
   {
      gout.drawGPSCenter(pos, angle.getRadians());
   }
};

/**************************
 * HUBBLE LEFT WING
 * Part
**************************/
class HubbleLeft : public Satellite
{
public:
   // constructor
   HubbleLeft(const Satellite& parent, const Angle& direction) : Satellite(parent, direction)
   {
      radius = 8.0;
   }
   
   void draw(ogstream& gout) override
   {
      gout.drawHubbleLeft(pos, angle.getRadians());
   }
};

/**************************
 * HUBBLE RIGHT WING
 * Part
**************************/
class HubbleRight : public Satellite
{
public:
   // constructor
   HubbleRight(const Satellite& parent, const Angle& direction) : Satellite(parent, direction)
   {
      radius = 8.0;
   }
   
   void draw(ogstream& gout) override
   {
      gout.drawHubbleRight(pos, angle.getRadians());
   }
};

/**************************
 * HUBBLE COMPUTER
 * Part
**************************/
class HubbleComputer : public Satellite
{
public:
   // constructor
   HubbleComputer(const Satellite& parent, const Angle& direction) : Satellite(parent, direction)
   {
      radius = 7.0;
   }
   
   void draw(ogstream& gout) override
   {
      gout.drawHubbleComputer(pos, angle.getRadians());
   }
};

/**************************
 * HUBBLE TELESCOPE
 * Part
**************************/
class HubbleTelescope : public Satellite
{
public:
   // constructor
   HubbleTelescope(const Satellite& parent, const Angle& direction) : Satellite(parent, direction)
   {
      radius = 8.0;
   }
   
   void draw(ogstream& gout) override
   {
      gout.drawHubbleTelescope(pos, angle.getRadians());
   }
};

/**************************
 * STARLINK BODY
 * Part
**************************/
class StarlinkBody : public Satellite
{
public:
   // constructor
   StarlinkBody(const Satellite& parent, const Angle& direction) : Satellite(parent, direction)
   {
      radius = 6.0;
   }
   
   void draw(ogstream& gout) override
   {
      gout.drawStarlinkBody(pos, angle.getRadians());
   }
};

/**************************
 * STARLINK ARRAY
 * Part
**************************/
class StarlinkArray : public Satellite
{
public:
   // constructor
   StarlinkArray(const Satellite& parent, const Angle& direction) : Satellite(parent, direction)
   {
      radius = 8.0;
   }
   
   void draw(ogstream& gout) override
   {
      gout.drawStarlinkArray(pos, angle.getRadians());
   }
};
