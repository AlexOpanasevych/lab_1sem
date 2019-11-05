//Check is the king checked 
#include <stdio.h>

const int fieldSize = 8;
const int field[8][8] = {
    {'.','.','k','.','.','.','.','.'},
    {'p','p','.','.','p','p','p','p'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','b','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'P','p','P','P','P','P','P','P'},
    {'K','.','.','.','.','.','.','.'}
};

// 1 - rigth down, 2 - rigth up, 3 - left up, 4 - left down  

int diag(int x, int y, int size, const int (*field)[size], int direction, char dest){
    switch (direction){
        case 1: //rigth down
            for(int i=1; i<size; i++){
                if(x+i < size && y+i < size){
                    if(field[y+i][x+i] == '.'){

                    }else if(field[y+i][x+i] == dest){
                        return 1;
                    }else{
                        break;
                    }
                }else{
                    break;
                }
            }   
            break;
        case 2: // rigth up
            for(int i=1; i<size; i++){
                if(x+i < size && y-i >= 0){
                    if(field[y-i][x+i] == '.'){

                    }else if(field[y-i][x+i] == dest){
                        return 1;
                    }else{
                        break;
                    }
                }else{
                    break;
                }
            }   
            break;
        case 3: // left up
            for(int i=1; i<size; i++){
                if(x-i >= 0 && y-i >= 0){
                    if(field[y-i][x-i] == '.'){

                    }else if(field[y-i][x-i] == dest){
                        return 1;
                    }else{
                        break;
                    }
                }else{
                    break;
                }
            }   
            break;
        case 4: // left down
            for(int i=1; i<size; i++){
                if(x-i >= 0 && y+i < size){
                    if(field[y+i][x-i] == '.'){

                    }else if(field[y+i][x+i] == dest){
                        return 1;
                    }else{
                        break;
                    }
                }else{
                    break;
                }
            }   
            break;
        default: 
            break;
    }
    return 0;
}

// 1 - right, 2 - left, 3 - up, 4 - down
int plus(int x, int y, int size, const int (*field)[size], int direction, char dest){
    switch (direction){
        case 1: // rigth
            for(int i=x+1; i<size; i++){
                if(field[y][i] == '.'){

                }else if(field[y][i] == dest){
                    return 1;
                }else{
                    break;
                }
            }   
            break;
        case 2: // left
            for(int i=x-1; i >= 0; i--){
                if(field[y][i] == '.'){

                }else if(field[y][i] == dest){
                    return 1;
                }else{
                    break;
                }
            }   
            break;
        case 3: // up
            for(int i=y+1; i<size; i++){
                if(field[i][x] == '.'){

                }else if(field[i][x] == dest){
                    return 1;
                }else{
                    break;
                }
            }   
            break;
        case 4: // down
            for(int i=y-1; i >= 0; i--){
                if(field[i][x] == '.'){

                }else if(field[i][x] == dest){
                    return 1;
                }else{
                    break;
                }
            }   
            break;
        default: 
            break;
    }
    return 0;
}


// 0 - up, 1 - down; 
int pawnCheck(int x, int y, int size, const int (*field)[size], int direction, char dest){
    if(direction){
        if(x+1 < size && y-1 >= 0){
            if(field[y-1][x+1] == dest){
                return 1;
            }
        }
        if(x-1 >= 0 && y-1 >= 0){
            if(field[y-1][x-1] == dest){
                return 1;
            }
        }
    }else{
        if(x+1 < size && y+1 < size){
            if(field[y+1][x+1] == dest){
                return 1;
            }
        }
        if(x-1 >= 0 && y+1 < size){
            if(field[y+1][x-1] == dest){
                return 1;
            }
        }
    }
    return 0;
}
int knightCheck(int x, int y, int size, const int (*field)[size], char dest){
    if(x+2 < size && y-1 >= 0){
        if(field[y-1][x+2] == dest){
            return 1;
        }
    }
    if(x-2 >= 0 && y-1 >= 0){
        if(field[y-1][x-2] == dest){
            return 1;
        }
    }
    if(x+2 < size && y+1 < size){
        if(field[y+1][x+2] == dest){
            return 1;
        }
    }
    if(x-2 >= 0 && y+1 < size){
        if(field[y+1][x-2] == dest){
            return 1;
        }
    }

    if(x+1 < size && y-2 >= 0){
        if(field[y-2][x+1] == dest){
            return 1;
        }
    }
    if(x-1 >= 0 && y-2 >= 0){
        if(field[y-2][x-1] == dest){
            return 1;
        }
    }
    if(x+1 < size && y+2 < size){
        if(field[y+2][x+1] == dest){
            return 1;
        }
    }
    if(x-1 >= 0 && y+2 < size){
        if(field[y+2][x-1] == dest){
            return 1;
        }
    }
    return 0;
}


int Pawn(int x, int y, int size, char color ,const int (*field)[size]){
    if(color == 'w'){
        if(pawnCheck(x,y,size,field,1,'k')){
            return 1;
        }
    }else{
        if(pawnCheck(x,y,size,field,0,'K')){
            return 1;
        }
    }
    return 0;
}

int Knight(int x, int y, int size, char color ,const int (*field)[size]){
    if(color == 'w'){
        if(knightCheck(x,y,size,field,'k')){
            return 1;
        }
    }else{
        if(knightCheck(x,y,size,field,'K')){
            return 1;
        }
    }
    return 0;
}

int Bishop(int x, int y, int size, char color ,const int (*field)[size]){
    for(int i=1; i<5; i++){
        if(color == 'w'){
            if(diag(x, y, size, field, i, 'k')){
                return 1;
            }
        }else{
            if(diag(x, y, size, field, i, 'K')){
                return 1;
            }
        }
    }
    return 0;
}
int Rook(int x, int y, int size, char color ,const int (*field)[size]){
    for(int i=1; i<5; i++){
        if(color == 'w'){
            if(plus(x, y, size, field, i, 'k')){
                return 1;
            }
        }else{
            if(plus(x, y, size, field, i, 'K')){
                return 1;
            }
        }
    }
    return 0;
}
int Queen(int x, int y, int size, char color ,const int (*field)[size]){
    for(int i=1; i<5; i++){
        if(color == 'w'){
            if(plus(x, y, size, field, i, 'k')){
                return 1;
            }
            if(diag(x, y, size, field, i, 'k')){
                return 1;
            }
        }else{
            if(plus(x, y, size, field, i, 'K')){
                return 1;
            }
            if(diag(x, y, size, field, i, 'K')){
                return 1;
            }
        }
    }
    return 0;
}

// 0 - no king, 1 - black king, 2 - white king
int chess(int size, const int (*field)[size]){
//    printf("\n%c",field[1][2]);
    for(int y=0; y<size; y++){
        for(int x=0; x<size; x++){
            switch (field[y][x]){
                case 'B':
                    if(Bishop(x,y,size,'w',field)){
                        return 1;
                    }
                    break;
                case 'b':
                    if(Bishop(x,y,size,'b',field)){
                        return 2;
                    }
                    break;
                case 'R':
                    if(Rook(x,y,size,'w',field)){
                        return 1;
                    }
                    break;
                case 'r':
                    if(Rook(x,y,size,'b',field)){
                        return 2;
                    }
                case 'Q':
                    if(Queen(x,y,size,'w',field)){
                        return 1;
                    }
                    break;
                case 'q':
                    if(Queen(x,y,size,'b',field)){
                        return 2;
                    }
                    break;
                case 'P':
                    if(Pawn(x,y,size,'w',field)){
                        return 1;
                    }
                    break;
                case 'p':
                    if(Pawn(x,y,size,'b',field)){
                        return 2;
                    }
                    break;
                case 'N':
                    if(Knight(x,y,size,'w',field)){
                        return 1;
                    }
                    break;
                case 'n':
                    if(Knight(x,y,size,'b',field)){
                        return 2;
                    }
                    break;
                default:
                    break;
            }

        }
    }
    return 0;
}

int main(void){
    int temp = chess(fieldSize, field);
    if(temp){
        if(temp == 1){
            printf("\nblack king is in check");
        }else{
            printf("\nwhite king is in check");
        }
    }else{
        printf("\nno king is in check");
    }
    return 0;

}