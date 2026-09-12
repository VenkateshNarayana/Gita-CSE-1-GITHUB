/*Application of stack  - Postfix Evaluation
Algorithm 
step1 : read infix expression from left to right
step2 : if token is Operand then push into stack.
step3 : a)if token is operator, pop the top two operands (op2, then op1).
        b)Compute a ? b ( ? = operator) and push the result back to stack
step4 : After the last token, the single value left on the stack is the answer.

*/
#include<stdio.h>
#define MAX_SIZE 20
int top = -1; //current index tracker

void push(int[],int); //param1:array name ;param2:valuea
void traverse(int[]); //param1:array name
int is_full();        //return 1 if its full else 0
int is_empty();       //return 1 if its empty else 0
int peek(int[]);      //param1:array name
int pop(int[]);       //param1:array name

int main(){
	int stack[MAX_SIZE]={0};//declare and initialize to zero with size as MAX_SIZE
	char postfix[20]= "23+41-*"; //postfix expression
	int result = 0;
	int i=0,op1=0,op2=0; //use i for tracking characters of infix and k for tracking characters in postfix
	//step1 : read infix expression from left to right
	while(postfix[i]!='\0'){ //'\0' string terminator
		//step2 : if token is Operand then push into stack.
		if(postfix[i]!='+' && postfix[i]!='-' &&
		   postfix[i]!='*' && postfix[i]!='/' && postfix[i]!='%'){
		   	//operand
			push(stack,postfix[i]-'0');//subtract the ascii value with 0 to get the actual value
			traverse(stack);
		}else{
			//operator - step3 : a)if token is operator, pop the top two operands (op2, then op1).
            op2 = pop(stack); //pop1 item is always operand 2
			op1 = pop(stack); //pop2 item is always operand 1
			
			//b)Compute op1 ? op2 ( ? = operator) and push the result back to stack
			switch(postfix[i]){
				case '+': result = op1 + op2 ; break;
				case '-': result = op1 - op2 ; break;
				case '*': result = op1 * op2 ; break;
				case '/': result = op1 / op2 ; break;
				case '%': result = op1 % op2 ; break;;
				default : printf("%c Invalid Operator",postfix[i]);
			}
			//push the result back to stack
			push(stack,result);
			traverse(stack);
		}
		
		i++;
	}
	//step4 : After the last token, the single value left on the stack is the answer.
	result = pop(stack);
	printf("\nPostfix Expression   : %s",postfix);
	printf("\n\nPostfix Evaluation : %d",result);
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
