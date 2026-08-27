/*1. Write a program to print the value and address of a variable using a pointer
  2. Swap two numbers using pointers. */
#include<stdio.h> //preprocessor directive
//global declaration
void swap(int,int);
void swap_by_ref(int*,int*);
int main(){ //main function
	int x; //basic datatype of integer type x
	int* ptrx; //pointer variable of ptrx can store addresses of type integer only
	ptrx = &x ;//store the address using address of operator
	printf("\n%p is the address stored in ptrx",ptrx);
	printf("\n%p is the address of x",&x);
	x=10;
	printf("\n%d is value of x",x);
	printf("\n%d is value of x using ptrx",*ptrx); //using deference - to get what is stored in the ptrx (address)
	//manipulate value of x =20 using ptrx
	*ptrx = 20;
	printf("\n%d is value of x after manipulation using ptrx",x);
	//swap 2 numbers
	int y=40;
	printf("\nx=%d ,y =%d before swapping",x,y);
	swap(x,y);//function call
	printf("\nx=%d ,y =%d after swapping",x,y);
	swap_by_ref(&x,&y);//function call using by reference(send the address) use addressof operator
	printf("\nx=%d ,y =%d after swapping",x,y);
	
}
//function definitions
void swap_by_ref(int* x, int* y){
	int temp;
	temp = *x;
	*x    = *y;
	*y    = temp;
}
void swap(int x, int y){
	int temp;
	temp = x;
	x    = y;
	y    = temp;
}
