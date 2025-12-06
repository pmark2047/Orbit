/**********************************************************************
* Source File:
*    Orbit Lab
* Author:
*    Peyton and Jackson
* Summary:
*    Orbit
************************************************************************/

#include "test.h"
#include "position.h"
#include "velocity.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "satellite.h"
#include <iostream>
#include "star.h"
#include "sputnik.h"
#include "dragon.h"
#include "GPS.h"
#include "hubble.h"
#include "starlink.h"
#include "ship.h"


using namespace std;

const double TIME_DILATION = 40.0;

/*********************************
 * ORBIT SIMULATOR
 * Let's get it going
 *********************************/
class Simulator
{
public:
   Simulator()
   {
      
      satellites.push_back(new Sputnik());
      satellites.push_back(new Dragon());
      satellites.push_back(new Hubble());
      satellites.push_back(new Starlink());
      satellites.push_back(new GPS());
      satellites.push_back(new Ship());
      
      
      for (int i = 0; i < 500; i++)
      {
         Star* s = new Star();
         s->position.setPixelsX(random(-500.0, 500.0));
         s->position.setPixelsY(random(-500.0, 500.0));
               
         stars.push_back(s);
      }
   }
   
   ~Simulator()
      {
         for (Satellite* sat : satellites)
            delete sat;
         satellites.clear();
      
         for (Star* s : stars)
            delete s;
         stars.clear();
      }
   
   void update(const Interface* pUI)
      {
         // this handles input
         for (auto it = satellites.begin(); it != satellites.end(); it++)
            {
               (*it)->input(*pUI, satellites);
            }
      
         // this handles movement
         for (Satellite* sat : satellites)
         {
            sat->move(TIME_DILATION);
         }
      
         // this will attempt to handle collision
         for (auto it1 = satellites.begin(); it1 != satellites.end(); ++it1)
         {
            for (auto it2 = next(it1); it2 != satellites.end(); ++it2)
            {
               Satellite* sat1 = *it1;
               Satellite* sat2 = *it2;
               
               double distance = computeDistance(sat1->getPosition(), sat2->getPosition());
               double minDistance = sat1->getRadius() + sat2->getRadius();
               
               if(distance < minDistance + 300000)
               {
                  sat1->kill();
                  sat2->kill();
               }
            }
         }
      
         // this will destroy stuff
         for (auto it = satellites.begin(); it != satellites.end();)
         {
            if ((*it)->isDead())
            {
               (*it)->destroy(satellites);
               delete *it;
               it = satellites.erase(it);
            }
         else
         {
            ++it;
         }
      }
      }
   
   // Draw stuff
   void draw()
   {
      ogstream gout;
      
      // draw a star
      for (Star* s : stars)
      {
         s->phase += 1;
         gout.drawStar(s->position, s->phase);
      }
      
      // draw earth
      Position earthpos(0.0, 0.0);
      gout.drawEarth(earthpos, 0.0);
      
      // draw satellites
      for (Satellite* sat : satellites)
      {
         sat->draw(gout);
      }
   }
private:
   list<Satellite*> satellites;
   int phaseShifter = 0;
   list<Star*> stars;
};

/*************************************
 * CALLBACK
 * continuous display
 *************************************/
void callBack(const Interface* pUI, void* p)
{
   Simulator* pSimulator = (Simulator*)p;

   pSimulator->update(pUI);
   pSimulator->draw();
}



/*********************************
 * MAIN - Where it all begins...
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

   // run all the unit tests
   testRunner();
   
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0);
   ptUpperRight.setPixelsX(700.0);
   ptUpperRight.setPixelsY(700.0);
   
   Interface ui(argc, argv, "Orbit", ptUpperRight);
   
   Simulator simulator;

   ui.run(callBack, &simulator);
   
   return 0;
}
