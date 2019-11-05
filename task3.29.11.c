/* ------------------------------------------------------------------------------------------------<Header>-
 Name: task12.3.c
 Title: Task 3 for 12 practice.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-11-29
 Revised: _
 Description: На пироге расположено 2N вишен, причем 1 < N < 50. Требуется поделить пирог на две части
одним прямым разрезом, проходящим через центр пирога, так, чтобы каждому из двоих едоков
досталось одинаковое количество пирога и одинаковое количество вишен.
 -------------------------------------------------------------------------------------------------</Header>-*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 2

int main(void){
	int A = -500, B = -500;
	int cherry[2][2*N];
	srand(time(NULL));
	for(int j = 0; j < 2*N; j++)
		for(int i = 0; i < 2; i++)
			cherry[i][j] = -1*100 + rand() % 200;
	for(A = -500; A <= 500; A++)
		for(B = -500; B <= 500; B++){
			int side[2] = {0,0};
			for(int j = 0; j < 2*N; j++){
				int cherry1 = (A*cherry[0][j] + B*cherry[1][j]);

				if(cherry1 > 0)
					side[1]++;
				if(cherry1 < 0)
					side[0]++;
			}
			if(side[0] == side[1]){
				printf("A = %d; B = %d\n", A, B);
				return 0;
			}
		}
	return 0;
}