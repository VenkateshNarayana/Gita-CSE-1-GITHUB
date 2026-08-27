#include<stdio.h>
void sum_numbers(int,int,int*);
int main(){
	int num1, num2, sum;
	printf("Enter the 2 numbers:");
	scanf("%d %d",&num1,&num2);
	sum_numbers(num1,num2,&sum);
	printf("sum= %d",sum);
	return 0;
}
void sum_numbers(int num1,int num2,int* ptr_sum){
	*ptr_sum = (num1+num2);
}
