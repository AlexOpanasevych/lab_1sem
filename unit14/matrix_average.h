#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int borderH;
int borderW;
int* matrix;

void smooth(int* input_matrix, int width, int height); // smooth the matrix, input: pointer to matrix, width, height
void average_element(int inpX, int inpY); //private function. Do not use;
bool check_placement(int inpX, int inpY); //private function. Do not use;