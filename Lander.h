/**************************************************************
 * Header File:
 *  lander.h
 * Author:
 *  Gergo Medveczky 
 * Summary:
 *  lander class with attributes that will be set and retrieved.
 **************************************************************/
#ifndef	Lander_h
#define	Lander_h
#include "point.h"
#include "Velocity.h"
#include <stdio.h>
#include "Star.h"
#define GRAVITY 0.0425
#define PI 3.14159265

using namespace std;

/*************************
 * Lander class to store
 * attributes about the
 * generated lander
 *************************/
class Lander
{
private:
	int fuel;
	Point point;
	Velocity velocity;
	bool alive;
	bool landed;
	const int landerWidth = 20;

	// Calculate acceleration due to weight
	const double thrust = 45000 / 15103;
	double angle;

	// Changes degree angle to radians
	double degreesToRadians() { return 2 * PI * angle / 360; }

public:
	// Default constructor
	Lander()
	{
		angle = 0;
		alive = true;
		landed = false;
		fuel = 5000;
		point.setX(random(200, 1000));
		point.setY(random(400,650));
	}

	// Getters
	double getAngle()				const { return angle;				}
	Point getPoint()				const { return point;				}
	int getLanderWidth()			const { return landerWidth;		}
	int getFuel()					const { return fuel;					}
	bool isAlive()					const { return alive;				}
	bool isLanded()				const { return landed;				}

	// Setters
	void setAlive(bool alive)			{ this->alive = alive;		}
	void setFuel(int fuel)				{ this->fuel = fuel;			}
	void setLanded(bool landed)		{ this->landed = landed;	}

	// Calculates current speed
	float calcSpeed();

	// applies thrust in direction
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustBottom();

	// advance
	void advance();

	// bool lunch the thrusts
	bool canThrust() const;

	//Apply Gravity
	void applyGravity();

	// wraps if lander passes edges of screen
	void wrapping();
};

#endif /* Lander_h */
