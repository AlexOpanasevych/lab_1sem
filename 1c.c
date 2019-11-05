#include <stdio.h>

int SumAround(int m[][])
{
    int sumleft = 0, sumtop = 0, sumbot = 0, sumright = 0;
    int height, width;

    for (int i = 0; i < width; i++) {
        sumtop += m[0, i];
	}
    for (int i = 0; i < width; i++){
        sumbot += m[height - 1, i];
	}
    for (int i = 1; i < height - 1; i++)
    {
        sumleft += m[i, 0];
        sumright += m[i, width - 1];
    }
    return sumleft + sumtop + sumbot + sumright;
}

int main(void)
{
	int height, width;
	int sumleft = 0, sumtop = 0, sumbot = 0, sumright = 0;
	int m[height][width], n;
	do {
	printf("Input count of rows and columns :\n");
	scanf("%d",&n);
	} while(n > 10);
    n = height, width;
	printf("Введите елементы матрицы :\n");
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			scanf("%d", &m[height][width]);
		}
	}
	m[height][width], SumAround(m[height][width]);
	printf("%d", sumleft + sumtop + sumbot + sumright);
	return 0;
}