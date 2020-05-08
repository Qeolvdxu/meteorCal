#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("You must enter the Mass(kg) and Fall Distance(m)\n");	
		return 2;
	} 

	double mass = atof(argv[1]);// kilograms
	const double earthMass = 5.972 * pow(10, 24);
	const double earthRadius = 6370000;

	double initDistance = atof(argv[2]) + earthRadius;  // meters
	double distance = initDistance;

	double initVel = 0;
	double vel = initVel;

	double initTime = 0;
	double time = initTime;

	double gravity = 9.8; // m/s^2

	double keneticE = 0;  // jouls

	double acceleration = 0;

	double gravityDifference = 0;

	double impactForce = 0; // Newtons

	printf("%.2f\n", gravity);

	// Drop
	acceleration = gravity;
	while(distance > earthRadius)
	{
		gravityDifference = 1 / (distance / 2);
		gravity = gravity - (gravityDifference * gravity);  
		acceleration = gravity;
		vel = initVel + (acceleration * time);	
		keneticE = (mass * (pow(vel , 2))) * 0.5;		
		distance = distance - vel;
		impactForce = keneticE / (distance - earthRadius);
		printf("mass: %.2fkg      distance: %.2fm       time: %.2fs      velocity: %.2fm/s      kenetic energy: %.2fj       acceleration: %.8fm/s\n", mass, distance - earthRadius, time, vel, keneticE, acceleration);

		time++;
	}
		printf("The object hit the ground with %.2f Newtons of impact force.\n",impactForce);

	return 0;
}
