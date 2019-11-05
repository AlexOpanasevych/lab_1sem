/* ------------------------------------------------------------------------------------------------<Header>-
 Name: task5.29.11.c
 Title: Task 5 for 12 practice.
 Group: TI-81
 Student: Opanasevych O.B
 Written: 2018-11-29
 Revised: _
 Description: Группа путешественников заранее договорилась делить расходы поровну. Так как неудобно делить
расходы по мере их поступления, поэтому каждый путешественник платит за определенные вещи,
такие, как еда, проживание, поездки на такси и билеты на самолет. После путешествия расходы
каждого участника суммируются, и происходит обмен деньгами так, что итоговая стоимость для
всех оказывается равной с точностью до одной копейки. Задача состоит в том, чтобы,
основываясь на списке расходов, определить минимальную сумму денег, которая должна поменять
хозяина, для того чтобы уравнять (с точностью до копейки) расходы всех путешественников.
 -------------------------------------------------------------------------------------------------</Header>-*/
#include <stdio.h>
#define MAX_STRANGE 1000
#define MAX_VALUE 10000
#define MAX_TRAVELS 1000
float average(float *cash,int s);
float MinMoney(float *cash,int s);
int main(){
	int travels, s;
	float cash[MAX_STRANGE];
	printf("Enter the count of travels :\n");
	scanf("%d", &travels);
	if(travels < 1 && travels < MAX_TRAVELS) return 0;
	for(int i = 0; i < travels; i++){
		do {
			printf("Enter the count of travelers(less than %d) :\n", MAX_STRANGE);
			scanf("%d", &s);
		} while(s > MAX_STRANGE && s < 2);
		for(int i = 0;i < s;i++){
			do {
				printf("Enter the sum of money each traveler had spent(less than %d) :\n", MAX_VALUE);
				scanf("%f",&cash[i]);
			} while(cash[i] > MAX_VALUE && cash[i] != 0);
		}
		printf("%.2f\n", MinMoney(cash, s));
	}
	return 0;
}
float average(float *cash,int s){
	float sum = 0;
	for(int i = 0;i<s;i++){
		sum += cash[i];
	}
	float average = sum/s;
	return average;
}
float MinMoney(float *cash,int s){
	float sum = 0;
	for(int i = 0; i < s; i++){
		if(cash[i] < average(cash, s)){
			sum = sum + (average(cash, s) - cash[i]);
		}
	}
	return sum;
}
/* Output:
Enter the count of travels :
1
Enter the count of travelers(less than 1000) :
3
Enter the sum of money each traveler had spent(less than 10000) :
10
Enter the sum of money each traveler had spent(less than 10000) :
20
Enter the sum of money each traveler had spent(less than 10000) :
30
10.00 */