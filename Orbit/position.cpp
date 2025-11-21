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

double Position::metersFromPixels = 40.0;

 /************************************
  * POSITION : ADD
  ************************************/
void Position::add (const Acceleration & a, const Velocity & v, double t)
{
   x += (v.getDX() * t) + (0.5 * a.getDDX() * t*t);
   y += (v.getDY() * t) + (0.5 * a.getDDY() * t*t);
}

std::ostream& operator << (std::ostream& out, const Position& pt)
{
   out << "(" << pt.getMetersX() << "m, " << pt.getMetersY() << "m)";
   return out;
}

Position& Position::operator=(const Position& pt)
{
   x = pt.x;
   y = pt.y;
   return *this;
}

std::istream& operator >> (std::istream& in, Position& pt)
{
   double x;
   double y;
   in >> x >> y;
   pt.setMetersX(x);
   pt.setMetersY(y);
   return in;
}
