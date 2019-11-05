#include <stdio.h>

int set_mode(int mode) {
	if (mode == -1) {
		return -1;
	}
	if (mode != -1 && mode != 0 && mode != 1) {
		printf ("Error. Wrong mode");
		mode = 0;
	}
	return 1;
}

int get_info(float fuel, float distance, int mode) {
	if (mode == 0) {	
		printf ("Enter distance traveled in kilometers: ");
		scanf ("%f", &distance);
		printf ("Enter fuel consumed in liters: ");
		scanf ("%f", &fuel);
	}
	if (mode == 1) {	
		printf ("Enter distance traveled in miles: ");
		scanf ("%f", &distance);
		printf ("Enter fuel consumed in gallons: ");
		scanf ("%f", &fuel);
	}
	return 2;
}

float show_info(float fuel, float distance, float consumption, int mode) {
	//printf (" %f %f ", fuel, distance);
	float consumption1 = consumption;
	if (mode == 0) {
		consumption1 = fuel * 100 / distance;
		printf ("Fuel consumption is %.2f kilometer per litter \n", consumption1);
	}
	if (mode == 1) {
		fuel /= 3.78;
		consumption1 = fuel * 100 / distance;
		printf ("Fuel consumption is %.2f miles per gallon \n", consumption1);
	}
	return 3;
}