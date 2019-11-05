#include "fuel13-2b.h"

int set_mode() {
    int mode;
    do{
        scanf("%d", &mode);
        getchar();
    if(mode != 0 && mode != 1) printf("you entered invalid value!!! try again!\n");
    }while(mode != 0 && mode != 1);
    return mode;
}

void show_info(float distance, float fuel, int mode) {
    if(mode == 0){
        printf("\nFuel consumption is %.2f liters per 100 km\n", fuel*KM_PER_LITER/distance);
    }
    else{
        printf("\nFuel consumption is %.2f miles per gallon\n", distance/fuel);
    }
}
void get_info(){
    float distance, fuel; 
    int mode;
    mode = set_mode();
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
    show_info(distance, fuel, mode);
}