#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	if (argc != 2){
		printf("You entered mote than 2 arguments!!!\n");
		return -1;
	}
	int nlamp = atoi(argv[1]);
	int counter;
	if(nlamp == 0){return 0;}
	for (int i = 1; i < nlamp; i++){
		if(nlamp%i == 0){
			counter++;
		}
		
	}
	if(counter % 2 == 1) {
			printf("no\n");
		}
		else printf("yes\n");
}