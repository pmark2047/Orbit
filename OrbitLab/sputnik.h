#pragma once
#include <cmath>
using namespace std;

// for unit tests
class TestPosition;
class TestVelocity;
class TestAcceleration;

// for add()
class Acceleration;
class Angle;
class Position;
class Velocity;
class Sattelite;

//(-36, 515, 095.13 m, 21, 082, 000.0 m) and the initial velocity is(2050.0 m / s, 2684.68 m / s).
//Sattelite base class

class Sputnik : Sattelite
{
public:
	Sputnik() {
		Position position = Position(-36515095.13, 21082000.0);
		Velocity velocity = Velocity(2050.0, 2684.68);
	}

	addPosition(double x, double y) {}
	
private:

};