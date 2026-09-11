/*Application of stack  - Infix to postfix expression
Algorithm 
step1 : read infix expression from left to right
step2 : if token is Operand then append directly to output.
step3 : if token is ‘(’ then push onto the stack
step4 : if token is ‘)’ then pop to output until ‘(’ is found; discard both parens
step5 : if token is Operator then pop & append to output while stack-top has precedence >= precedence of token. 
        after this push current operator(infix).
step6 : End of input  then check if stack is not empty then pop all remaining operators to output 

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

int operator_precedence(char oper);
int main(){
	int stack[MAX_SIZE]={0};//declare and initialize to zero with size as MAX_SIZE
	char infix[20] = "(2+3)*(4-1)"; //infix expression
	char postfix[20]= ""; //empty string
	int i=0, k=0,pop_item,peek_item; //use i for tracking characters of infix and k for tracking characters in postfix
	//step1 : read infix expression from left to right
	while(infix[i]!='\0'){ //'\0' string terminator
		//step2 : if token is Operand then append directly to output.
		if(infix[i]!='(' && infix[i]!=')' && 
		   infix[i]!='+' && infix[i]!='-' &&
		   infix[i]!='*' && infix[i]!='/' && infix[i]!='%'){
			//if operand push to output string
			postfix[k++]= infix[i]; //append to output string
		}
		//step3 : if token is ‘(’ then push onto the stack
		else if(infix[i]=='('){
			push(stack,infix[i]);//push open parenthesis
			traverse(stack);
		}
		//step4 : if token is ‘)’ then pop to output until ‘(’ is found; discard both parens
		else if(infix[i]==')'){
			pop_item = pop(stack);
			while(pop_item!='('){
				postfix[k++]= pop_item; //append to output string
				//pop item
				pop_item = pop(stack);
			}
		}
		//step5 : if token is Operator then pop & append to output while stack-top has precedence >= precedence of token.
		else {
			peek_item = peek(stack);
			while(!is_empty() && 
			       peek_item !='(' && 
				   operator_precedence(peek_item)>operator_precedence(infix[i])){
				   	
				   	//pop item
					pop_item = pop(stack);
					postfix[k++]= pop_item; //append to output string
					peek_item = peek(stack);			
			}
			//push into stack the infix operator
			push(stack,infix[i]);//push the infix operator after removing all the operators from stack until '('
			traverse(stack);
		}
		i++;
	}
	//step6 : End of infix string then check if stack is not empty then pop all remaining operators to output 
	while(!is_empty()){
		postfix[k++]=pop(stack); //append into output string
	}
	//append a string terminator 
	postfix[k++]='\0';
	
	printf("\nInfix Expression: %s\n",infix);
	printf("\nPostfix Expression: %s",postfix);
}
int operator_precedence(char oper){
	switch(oper){
		case '+':
		case '-': return 1;
		case '*':
		case '/':
		case '%': return 2;
		default : printf("%c Invalid Operator",oper);return -1;
	}	
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
		printf("%c ",stack[i]); //print all the elements of stack from bottom to top
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
