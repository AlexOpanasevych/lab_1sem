/* ----------------------------------------------------------------<Header>-
 Name: task12.1.c
 Title: Task 1 for 12 practice.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-11-29
 Revised: _
 Description:Требуется собрать в прямоугольную коробку коллекцию кругов.
  Для заданного набора кругов программа должна найти наименьшую
  прямоугольную коробку, в которую она поместятся. Все круги должны касаться
  дна коробки. Рисунок ниже показывает приемлемый способ упаковки для набора
  кругов, хотя, возможно, для данных конкретных кругов это не оптимальный
  способ. При  идеальной упаковке каждый круг должен касаться,
  по меньшей мере, одного другого.
 ------------------------------------------------------------------</Header>-*/
#include <stdio.h>
#include <math.h>

int main(void) {
	float size, r1, r2, r;
	float m[9] = {2,1,4};
	size = size + m[0] + m[2];
	for (int i=0; i<9; i++){
		r1=m[i];
		r2=m[i+1];
		r=sqrt(pow((r1+r2),2)-(pow(r1-r2, 2)));
		size += r;
		r=0;
	}
	
	printf ("%.3f", size);
	return 0;
}