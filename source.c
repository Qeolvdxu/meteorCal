#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
	if (argc != 4) // Force the user to add mass and distance arguments when they launch the program
	{
		printf("You must enter the Mass(kg), Fall Distance(m), and Velocity(m/2)\n Ex: meteorSim 10 100 20\n");	
		return 2; // return with error
	} 

	FILE *output = fopen("output.txt","w");

	// Initialize and calculate variables
	double mass = atof(argv[1]);// kilograms
	const double earthMass = 5.972 * pow(10, 24);
	const double earthRadius = 6370000;

	double initDistance = atof(argv[2]) + earthRadius;  // meters
	double distance = initDistance;

	double initVel = atof(argv[3]);		// m/2
	double vel = initVel;

	double initTime = 0;	// seconds
	double simTime = initTime;

	double gravity = 9.8; // m/s^2

	double keneticE = 0;  // jouls

	double acceleration = 0;  // m/s^2

	double gravityDifference = 0; //amount that will be subtracted from gravity

	double impactForce = 0; // Newtons

	fprintf(output,"TIMELINE\n mass		distance	time	velocity	kenetic energy		acceleration\n");

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

			simTime++;  // increase simTime by one second
			//Display Information to Terminal
			fprintf(output," %.2fkg      %.2fm       %.2fs      %.2fm/s      %.2fj       %.8fm/s\n", mass, distance - earthRadius, simTime, vel, keneticE, acceleration);
	}

		// Print out final results and stats
		fprintf(output,"\n\nFINAL RESULTS\n");
		fprintf(output," Impact Force: %.2f Newtons\n Distance: %.2f Meters\n Time: %.2f Seconds\n",impactForce, atof(argv[2]), simTime);

	fclose(output);
	return 0;
}
