#include "matrix_average.h"


void smooth(int* input_matrix, int width, int height){
    //printf("\nDebug: smooth started");
    borderH = height;
    borderW = width;
    matrix = input_matrix;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++){
            average_element(i,j);
            //printf("\n---------------------------------");
        }
    }
}




bool check_placement(int inpX, int inpY){
    //printf("\nDebug: checking placement of (%d,%d)",inpX,inpY);
    if(inpX >= borderW || inpY >= borderH || inpX < 0 || inpY < 0){
        //printf("\nDebug: Palcement incorrect");
        return false;
    }
        //printf("\nDebug: Palcement correct");
    return true;
}


void average_element(int inpX, int inpY){
    //printf("\nDebug: average started for item (%d,%d)",inpX, inpY);
    int sumNbr = 0;
    int sumCounter = 0;
    if(inpY >= borderH || inpX >= borderW || inpY < 0 || inpX < 0){
        fprintf(stderr,"Failed to process cell (%d,%d)",inpX, inpY);
        return;
    }



    //printf("\nDebug: average skipped errors");
    for(int idx = 1; idx < 9; idx+=2){
        //printf("\nDebug: average processing cells, idx=%d",idx);
        //printf("\nDebug: checking cords x=%d  y=%d",idx%borderW+inpX,idx/borderW+inpY);
        int x;
        int y;
        switch (idx){
            case 1:
                x=inpX;
                y=inpY-1;
                break;
            case 3:
                x=inpX-1;
                y=inpY;
                break;
            case 5:
                x=inpX+1;
                y=inpY;
                break;
            case 7:
                x=inpX;
                y=inpY+1;
                break;
        }

        if(check_placement(x,y)){
            sumNbr += matrix[y*borderW + x];
            //printf("\nDebug: average sum updated, sumNbr=%d",sumNbr);
            sumCounter++;
        }
    }

    matrix[inpY*borderW + inpX] =  sumNbr / sumCounter;
    //printf("\nDebug: average ended, matrix[%d,%d] updated witth value: %d",inpX,inpY, sumNbr / sumCounter);
}

/*Output
1 2 3
4 5 6
7 8 9
*/


/*
int check_placement(int inpX, int inpY){
    if(inpX == 0 && inpY == 0){
        return 1;
    }
    if(inpX == borderW-1 && inpY == borderH-1){
        return 9;
    }
    if(inpX == borderW-1 && inpY == 0){
        return 3;
    }
    if(inpY == borderH-1 && inpX == 0){
        return 7;
    }
    if(inpX == borderW-1){
        return 6;
    }
    if(inpY == borderH-1){
        return 8;
    }
    if(inpX == 0){
        return 4;
    }
    if(inpY == 0){
        return 2;
    }
    return 5;
}
*/
/*
int check_placement(int inpX, int inpY){
    if(inpX == -1 && inpY == -1){
        return 1;
    }
    if(inpX == borderW && inpY == borderH){
        return 9;
    }
    if(inpX == borderW && inpY == -1){
        return 3;
    }
    if(inpY == borderH && inpX == -1){
        return 7;
    }
    if(inpX == borderW){
        return 6;
    }
    if(inpY == borderH){
        return 8;
    }
    if(inpX == -1){
        return 4;
    }
    if(inpY == -1){
        return 2;
    }
    return 5;
}
*/
/*
void average_element(int inpX, int inpY){
    int sumNbr;
    if(inpY >= borderH || inpX >= borderW || inpY < 0 || inpX < 0){
        fprintf(stderr,"Failed to process cell (%d,%d)",inpX, inpY);
        return;
    }

    bool flag = false;
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            if(flag){
                switch (check_placement(x,y)){
                    case 1:
                        sumNbr += matrix[y*borderW + x+1];
                        sumNbr += matrix[(y+1)*borderW + x]; 
                        break;
                    case 3:
                        sumNbr += matrix[y*borderW + x-1];
                        sumNbr += matrix[(y+1)*borderW + x]; 
                        break;
                    case 7:
                        sumNbr += matrix[y*borderW + x+1];
                        sumNbr += matrix[(y-1)*borderW + x]; 
                        break;
                    case 9:
                        sumNbr += matrix[y*borderW + x-1];
                        sumNbr += matrix[(y-1)*borderW + x]; 
                        break;
                    case 2:
                        break;
                    case 4:
                        break;
                    case 6:
                        break;
                    case 8:
                        break;
                    default:
                        sumNbr += matrix[y*borderW + x+1];
                        sumNbr += matrix[(y+1)*borderW + x]; 
                        sumNbr += matrix[y*borderW + x-1];
                        sumNbr += matrix[(y-1)*borderW + x]; 
                        break;
                }
            }
            swapFlag(&flag);
        }
    }
}

*/