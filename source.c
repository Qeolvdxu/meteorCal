#include <math.h>
#include <stdio.h>


int main (int argc, int argv[])
{
	double mass = 10;		// mass is kg

	const double earthMass = 5.972 * pow(10, 24);
	const double earthRadius = 6370000;

	double initDistance = 100 + earthRadius;  // distance is m
	double distance = initDistance;

	double initVel = 10;
	double vel = initVel;

	double initTime = 0;
	double time = initTime;

	double gravity = (mass * earthMass)/(pow(initDistance, 2));

	double keneticE = 0;

	double acceleration = 0;

	double stalledDistance;
	
	double impactForce;

	printf("mass: %.2f      distance: %.2f       time: %.2f      velocity: %.2f      kenetic energy: %.2f       acceleration: %.2f \n", mass, distance - earthRadius, time, vel, keneticE, acceleration);

	// Drop
	acceleration = 9.8;
	while(distance > earthRadius)
	{
		vel = initVel + (acceleration * time);	
		keneticE = (mass * (pow(vel , 2))) * 0.5;		//kenertic Energy in J
		distance = distance - vel;
		if (distance <= earthRadius) //Impact
		{
			impactForce = keneticE / (earthRadius - distance);
			stalledDistance = earthRadius - distance;
		}

		time++;
		printf("mass: %.2f      distance: %.2f       time: %.2f      velocity: %.2f      kenetic energy: %.2f       acceleration: %.2f \n", mass, distance - earthRadius, time, vel, keneticE, acceleration);
	}
		printf("The object hit the ground with %.2f Newtons of impact force.\n",impactForce);

	return 0;
}
