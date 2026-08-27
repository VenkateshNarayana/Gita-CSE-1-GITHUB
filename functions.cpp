/*  WAP to find the square of a given number
*/
#include<stdio.h>
#include<conio.h>
//prototype (function declaration)
int find_square(int);		  //type 4- argument with return type
void print_even_or_odd(int);  //type 2- argument and no return type
int factorial(int);			  //type 4- argument with return type
void show_menu(); 			  //type 1 - no argument and no return type
int accept_user_input();      //type 3- no argument with return type
int main(){
	char ch;
	//function call
	do{
		int num;
		show_menu();
//		scanf("%c",&ch);
		ch = getch();
		printf("%c",ch);
		switch (ch){
			case '1':
					//take the user input
					num = accept_user_input();
					printf("\nSquare = %d",find_square(num));//function call
					break;
			case '2':
					//take the user input
					num = accept_user_input();
					print_even_or_odd(num); //function call wiht no return type.
					break;
			case '3':
					//take the user input
					num = accept_user_input();
					printf("\nFactorial = %d",factorial(num));//function call
					break;
			case '4':
					printf("\nThank you for using my application.");//function call
					break;
			default :
				printf("\nInvalid choice...Enter option between 1 and 4:");
		}
	}while(ch!='4');
	
	return 0;//for the main function
}
//function definitions
int accept_user_input(){
	int n;
	printf("\nEnter the number:");
	scanf("%d",&n); //addressof operator
	return n;
}
void show_menu(){
	printf("\n****************PROGRAM MENU************");
	printf("\nOption1: Square");
	printf("\nOption2: Even/Odd");
	printf("\nOption3: Factorial");
	printf("\nOption4: Exit");
	printf("\n\n Enter the choice:");
}
int factorial(int num){
	int fact = 1;
	for(int i=1;i<=num;i++){
		fact *= i; //fact = fact * i
	}
	return fact;
}
void print_even_or_odd(int num){
	printf("\n%d is %s",num,(num%2==0)?"even":"odd");
//	if(num%2==0){
//		printf("even");
//	}else{
//		printf("odd");
//	}
}
int find_square(int num){
	return (num*num);
}
