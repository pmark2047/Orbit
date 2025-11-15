/***********************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    Peyton and Jackson
 * Summary:
 *    Everything we need to know about a position
 ************************************************************************/

#include "position.h"
#include <math.h>  // for floor()
#include <cassert>
using namespace std;

 /************************************
  * POSITION : ADD
  ************************************/
void Position::add (const Acceleration & a, const Velocity & v, double t)
{
   x += (v.getDX() * t) + (0.5 * a.getDDX() * t*t);
   y += (v.getDY() * t) + (0.5 * a.getDDY() * t*t);
}
