/*3. Access array elements using a pointer*/
#include<stdio.h> //preprocessor directive
//global declarations

int main(){ //main function
	int arr[5]={1,2,3,4,5};
	int* ptr_arr;
	//point to base address
	ptr_arr = &arr[0]; //store the address of 0th element
	for(int i=0;i<5;i++){
		printf("\n%d is address of base element",&arr[i]);
	}
		
	printf("\nAddresses stored in pointer variable");
	for(int i=0;i<5;i++){
		printf("\n%d is address of base element",(ptr_arr+i));
	}
	
	printf("\nValues stored in pointer address variable");
	for(int i=0;i<5;i++){
		printf("\n%d is address of base element",* (ptr_arr+i));
	}
} 
//function definition
