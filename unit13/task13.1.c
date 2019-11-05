#include <stdio.h>
#include "fuel13-2a.h"

float fuel;
float distance;
float consumption;

int main(void) {
	int mode;
	printf ("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d", &mode);
	while (mode >= 0) {
		set_mode(mode);
		get_info(fuel, distance, mode);
		show_info(fuel, distance, consumption, mode);
		printf("Enter 0 for metric mode, 1 for US mode");
		printf(" (-1 to quit): ");
		scanf("%d", &mode);
	}
	printf("Done.\n");
	return 0;
}