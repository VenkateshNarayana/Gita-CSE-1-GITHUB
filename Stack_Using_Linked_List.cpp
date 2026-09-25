/* Applications of Linked List
   1. Implementation of Stack using linked List
   2. Implementation of Queue using linke list
   3. Representation & Evaluation of Polynomial expressions(add,subtract & multiply 2 polynomial) 
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	  int 			data;  //this is part1(information)
	  struct node* 	next;  //this is part2(pointer)
};
struct node* head = NULL;
struct node* tail = NULL;

//creating a node
struct node* create_node(int); //param1 - input data to store the part1(data- which is information part)

//insert
void push(int input_data);


//delete
void pop();

int is_empty();  // return 1 if linked list is empty else 0(underflow condition)
void peek();     // print the top(head->data)


//traverse
void traverse();
void free_list();

int main(){
	//perform push operations
	push(10);
	peek();
	push(20);
	peek();
	push(30);
	traverse();
	
	//pop operations
	pop();  //remove 30 
	peek(); //will fetch 20
	pop();  //remove 20
	peek(); //will fetch 10
	traverse();
	pop();  //remove 10
	peek(); //will fetch Top=NULL
	
	pop(); //will this work? NO - because stack is empty(underflow!!!)
	
	free_list();  //this our clean up activity to prevent memory leaks
	return 0;
}
void push(int input_data){
	//create a new node
	struct node* new_node = create_node(input_data);
	if(new_node==NULL) return; //memory allocation failed
	if(head==NULL){
		//if linked list is empty then make the new node as head and tail
		head = new_node;
		tail = new_node;
	}else{
		//if linked list is NOT empty then point new node to current head & move head to new node
		new_node->next = head; //point new node to current head
		head = new_node;       //move head to new node
	}
	printf("\nPushed %d(at Top) into Stack Successfully!!",input_data); 
}

void pop(){
	if(head==NULL){
		//linked is empty
		printf("\nStack is empty..cannot perform pop!!");
	}else{
		//step1 : store the address of head into temp
		struct node* temp = head;
		int deleted_data = head->data;
		//step2 : move the head to next node
		head = head->next;
		//step : free the temp
		free(temp);
		printf("\nPopped %d from Stack Successfully!!",deleted_data); 
	}
	
}
int is_empty(){
	return (head==NULL); //return 1 if list is empty else 0
}
void peek(){
	if(is_empty()){
		printf("\nTop=NULL");
	}else{
		printf("\nTop=%d",head->data);
	}
}
struct node* create_node(int input_data){  

	//param1 - input data to store the part1(data- which is information part)
	//use malloc to create the struct node
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node==NULL){
		printf("memory allocation failed.....");
		return NULL;
	}
	new_node->data = input_data; //store the input data into data part of the new node
	new_node->next = NULL ;      //store NULL in the pointer part
	return new_node;
}
void traverse(){
	struct node* temp;
	temp=head;
	if (is_empty()){
		printf("\nMy Stack[ empty ]");
	}else{
		printf("\nMy Stack[");
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp = temp->next;
		}
		printf("null]");
	}
}

void free_list(){
	if(!is_empty()){ //if list is not empty then ONLY free all the nodes
		struct node* temp;
		temp=head;
		while(head!=NULL){
			temp = head;      //store head into temp
			head = head->next;//move head to next node
			free(temp);       //free the old head
		}
		printf("\nAll noded are freed Successully!!");
	}
}
