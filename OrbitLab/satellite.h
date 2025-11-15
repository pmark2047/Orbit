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

//Sattelite base class
class Sattelite
{
private:
	Position position;
	Velocity velocity;
};