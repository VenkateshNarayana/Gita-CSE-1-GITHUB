/*Stack using arrays(fixed size)
Operation : Principle LIFO
Basic operations : push, pop, peek,is_empty,is_full,traverse

*/
#include<stdio.h>
#define MAX_SIZE 5
int top = -1; //current index tracker

void push(int[],int); //param1:array name ;param2:value
void traverse(int[]); //param1:array name
int is_full();        //return 1 if its full else 0
int is_empty();       //return 1 if its empty else 0
int peek(int[]);      //param1:array name
int pop(int[]);       //param1:array name

int main(){
	int stack[MAX_SIZE]={0};//declare and initialize to zero with size as MAX_SIZE
	push(stack,10);
	traverse(stack);
	push(stack,20);
	traverse(stack);
	push(stack,30);
	traverse(stack);
	push(stack,40);
	traverse(stack);
	push(stack,50);
	traverse(stack);
	push(stack,60);
	printf("peek=%d\n",peek(stack));
	traverse(stack);
	
	int pop_item = pop(stack);
	printf("popped item=%d",pop_item);
	traverse(stack);
	
	pop_item = pop(stack);
	printf("popped item=%d",pop_item);
	traverse(stack);
	
	pop_item = pop(stack);
	printf("popped item=%d",pop_item);
	traverse(stack);
	
	pop_item = pop(stack);
	printf("popped item=%d",pop_item);
	traverse(stack);
	
	pop_item = pop(stack);
	printf("popped item=%d",pop_item);
	traverse(stack);
	
	pop_item = pop(stack);//underflow condtion
	printf("popped item=%d",pop_item);
	traverse(stack);	
}
int pop(int stack[]){
	if(is_empty()){
		printf("Stack underflow...cannot perform pop.\n");
		return -1;
	}
	//remove the item from stack
	int pop_item = stack[top--]; //store the value at the top index into pop_item
	return pop_item;
}
void push(int stack[],int value){
	if(is_full()){
		printf("Stack overflow...cannot insert %d.\n",value);
		return;
	}
	//push the item to stack
	stack[++top] =  value; //push vakue at the top index
}
void traverse(int stack[]){
	printf("stack[");
	for(int i=0;i<=top;i++){
		printf("%d ",stack[i]); //print all the elements of stack from bottom to top
	}
	printf("]\n");
}
int is_full(){
	return (top==MAX_SIZE-1); //if top is at the last index of the Array then return 1 else 0
}
int is_empty(){
	return (top==-1); //if top is at -1 index then return 1 else 0
}
int peek(int stack[]){
	return stack[top]; //we will return the value of the top index 
}
