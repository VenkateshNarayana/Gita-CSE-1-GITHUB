/*
why functions to be declared in global declarations 
*/
#include <stdio.h>
int func_a(){
	int x;
	x = func_b();
	return x;
}
int func_b(){
	return 10;
}
int main(){
	printf("calling function a =%d",func_a());
	
	return 0;
}
