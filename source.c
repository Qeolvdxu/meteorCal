#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void clear_screen()
{
#ifdef WINDOWS
    system("cls");
#else
    // Assume POSIX
    system ("clear");
#endif
}

int main (int argc, char* argv[])
{
	if (argc != 3) // Force the user to add mass and distance arguments when they launch the program
	{
		printf("You must enter the Mass(kg) and Fall Distance(m)\n Ex: meteorSim 10 100\n");	
		return 2; // return with error
	} 
	system("clear");

	// Initialize and calculate variables
	double mass = atof(argv[1]);// kilograms
	const double earthMass = 5.972 * pow(10, 24);
	const double earthRadius = 6370000;

	double initDistance = atof(argv[2]) + earthRadius;  // meters
	double distance = initDistance;

	double initVel = 0;		// m/2
	double vel = initVel;

	double initTime = 0;	// seconds
	double simTime = initTime;

	double gravity = 9.8; // m/s^2

	double keneticE = 0;  // jouls

	double acceleration = 0;  // m/s^2

	double gravityDifference = 0; //amount that will be subtracted from gravity

	double impactForce = 0; // Newtons

	// Drop point
	acceleration = gravity;
	while(distance > earthRadius)  // while loop collects stats for the object falling every second 
	{
			// Calculate the change in gravity based on distance from the earths core and apply it to acceleration
			gravityDifference = 1 / (distance / 2);   
			gravity = gravity - (gravityDifference * gravity);  
			acceleration = gravity;

			vel = initVel + (acceleration * simTime);	// Calculate the velocity

			keneticE = (mass * (pow(vel , 2))) * 0.5;	// Find the amount of current kenetic enegry the object has this second

			distance = initDistance - (vel * simTime);  // Distance change to show the object falling

			impactForce = keneticE / (distance - earthRadius);  // Calculate the force of impact the object has on the earths surface

			//Display Information to Terminal
			printf("mass: %.2fkg      distance: %.2fm       time: %.2fs      velocity: %.2fm/s      kenetic energy: %.2fj       acceleration: %.8fm/s\n", mass, distance - earthRadius, time, vel, keneticE, acceleration);

			simTime++;  // increase simTime by one second
			system("sleep 1");
			system("clear");
	}

		// Print out final results and stats
		printf("The object hit the ground with %.2f Newtons of impact force.\n",impactForce);

	return 0;
}
