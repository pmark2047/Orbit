/**********************************************************************
* Source File:
*    Orbit Lab
* Author:
*    Peyton and Jackson
* Summary:
*    Orbit
************************************************************************/

#include "test.h"
#include "acceleration.h"
#include <iostream>
using namespace std;

/*********************************
 * MAIN - Where it all begins...
 *********************************/
class Main
{
public:
   Main(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
      ptSputnik.setPixelsX(ptUpperRight.getPixelsX() * random(0.1, 0.2));
      ptSputnik.setPixelsY(ptUpperRight.getPixelsY() * random(0.0, 0.0));
   }
   Position ptSputnik;

};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
int i = 1;
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Main* pMain = (Main*)p;
   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   gout.drawSputnik(pMain->ptSputnik, pMain->angleShip);

   // To get the sattelite to move in a circle
   Acceleration aGravity;
   pMain->ptSputnik.addMetersX(dx);
   pMain->ptSputnik.addMetersY(dy);


   int seconds = 86400;
   i += 1;
}



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

   return 0;
}
