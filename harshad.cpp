/* Create a udf for finding if a number given is harshad or not */
#include<stdio.h>
int checkHarshad(int);
int main(){
	int n;
	printf("Enter the number:");
	scanf("%d",&n);
	printf("%s",((checkHarshad(n))?"Harshad":"NOT HARSHAD"));
		
}
int checkHarshad(int num){
	int sum=0;
	int temp=num;
	while(num!=0){
		int digit = num % 10;	
		sum += digit;
		num/=10;
	}
	return (temp%sum==0);
}

