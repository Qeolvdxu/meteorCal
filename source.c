#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
	FILE *output = fopen("output.txt","w");

	// Initialize, calculate, and collect variables
	printf("Enter the mass of the Meteor in kg\n");
	double mass;// kilograms
	scanf("%lf",&mass);
	const double earthMass = 5.972 * pow(10, 24);
	const double earthRadius = 6370000;
	const double earthCrustDensity = 2.83; // g/cm^3

	int atmosphere = -1; //layers of atmosphere, 0 = Troposphere, 3 = Thermosphere

	printf("Enter the radius of the Meteor in m\n");
	double radius;
	scanf("%lf",&radius);
	double volume = 4/3 * 3.1459 * (radius*radius*radius); // Assuming meteor is sphere
	double length = radius * 2;

	double density = mass / volume;

	printf("Enter the fall distance of the Meteor in m\n");
	double initDistance;
	scanf("%lf",&initDistance);
	initDistance += earthRadius;
	double distance = initDistance;

	printf("Enter the inital velocity of the Meteor in m/2\n");
	double initVel;
	scanf("%lf",&initVel);
	double vel = initVel;

	double initTime = 0;	// seconds
	double simTime = initTime;

	double gravity = 9.8; // m/s^2

	double keneticE = 0;  // jouls

	double acceleration = 0;  // m/s^2

	double gravityDifference = 0; //amount that will be subtracted from gravity

	double impactForce = 0; // Newtons
	double impactDepth = 0; // m

	fprintf(output,"TIMELINE\n mass		distance	time	velocity	kenetic energy		acceleration		atmosphere\n");

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
			impactDepth = (density / earthCrustDensity) * length;


			simTime++;  // increase simTime by one second
			//Display Information to Terminal
			fprintf(output," %.2fkg      %.2fm      	 %.2fs      %.2fm/s     	 %.2fj       %.8fm/s		", mass, distance - earthRadius, simTime, vel, keneticE, acceleration);
			if (distance - earthRadius <= 10000 && distance - earthRadius > 0)
				fprintf(output,"Troposphere\n");	
			if (distance - earthRadius <= 50000 && distance - earthRadius > 10000)
				fprintf(output,"Stratosphere\n");
			if (distance - earthRadius <= 85000 && distance - earthRadius > 50000)
				fprintf(output,"Mesosphere\n");	
			if (distance - earthRadius <= 1000000 && distance - earthRadius > 85000)
				fprintf(output,"Thermosphere\n");	
			
	}

		// Print out final results and stats
		fprintf(output,"\n\nFINAL RESULTS\n");
		fprintf(output," Density: %.5f grams per cubic centimeter\n Impact Force: %.5f Newtons\n Distance: %.5f Meters\n Time: %.5f Seconds\n Depth: %.5f meters into the earths crust\n",density/1000, impactForce, atof(argv[2]), simTime, impactDepth);

	fclose(output);
	return 0; }
