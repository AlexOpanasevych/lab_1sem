#include <stdio.h>
#define KM_PER_LITER 100
float distance, fuel;
int mode;

void set_mode() {
    do{
        scanf("%d", &mode);
        getchar();
    if(mode != 0 && mode != 1) printf("you entered invalid value!!! try again!\n");
    }while(mode != 0 && mode != 1);
}
void get_info(){
    do{
        if(mode==0){
        printf("Enter distance traveled in kilometers: \n");
        } else printf("Enter distance traveled in miles: \n");
        scanf("%f", &distance);
    } while(distance <= 0);
    do{
        if(mode==0) {
        printf("\nEnter fuel consumed in liters: ");
        } else printf("\nEnter fuel consumed in gallons:");
        scanf("%f", &fuel);
    } while(fuel <= 0);
}
void show_info() {
    if(mode == 0){
        printf("\nFuel consumption is %.2f liters per 100 km\n", fuel*KM_PER_LITER/distance);
    }
    else{
        printf("\nFuel consumption is %.2f miles per gallon\n", distance/fuel);
    }
}
