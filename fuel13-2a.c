#include<stdio.h>
int mode,dis;
double fuel;

void get_info(){
	printf("Enter 0 for metric mode, 1 for US mode");
	scanf("%d",&mode);
	if(mode==0){
		printf("Enter distance traveled in kilometers:");
		scanf("%d", &dis);
		printf("Enter fuel consumed in liters:");
		scanf("%lf", &fuel);
	}
	if(mode==1){
		printf("Enter distance traveled in miles:");
		scanf("%d", &dis);
		printf("Enter fuel consumed in gallons:");
		scanf("%lf",&fuel);
	}
}

void show_info(){
	if(mode==0)
		printf("Fuel consumption is %lf liters",100.0/dis*fuel);
	if(mode==1)
		printf("Fuel consumption is %lf miles",dis/fuel);
}

void set_mode(int m){mode = m;}