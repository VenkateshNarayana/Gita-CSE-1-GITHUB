/* Applications of Linked List
   2. Implementation of Queue using linke list
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
void enqueue(int input_data); //insert_at_tail (entry from rear)

//delete
void dequeue();   //delete_at_head (exit from front)

//underflow check and peek operations
int is_empty();
void peek_front();
void peek_rear();

//traverse
void traverse();
void free_list();

int main(){
	
	//PERFORM - ENQUEUE
	enqueue(10);
	peek_front();
	peek_rear();
	enqueue(20);
	traverse();
	
	//PERFORM - DEQUEUE
	dequeue();
	traverse();
	
	dequeue();
	traverse();
	
	dequeue(); //will this work?NO - because Q is empty(underflow)
	
	free_list();  //this our clean up activity to prevent memory leaks
	return 0;
}

void enqueue(int input_data){
	//create a new node
	struct node* new_node = create_node(input_data);
	
	if(new_node==NULL) return; //memory allocation failed
	if(tail==NULL){
		//if linked list is empty then make the new node as head and tail
		head = new_node;
		tail = new_node;
	}else{
		//if linked list is NOT empty then point tail to the new node & move tail to new node
		tail->next = new_node; //point tail to new node 
		tail = new_node;       //move tail to new node
	}
	printf("\nEnqueued %d (at rear) Successfully!!",input_data); 
}
void dequeue(){
	if(head==NULL){
		//linked is empty
		printf("\nQueue is empty..cannot perform dequeue!!");
	}else{
		//step1 : store the address of head into temp
		struct node* temp = head;
		int deleted_data = head->data;
		//step2 : move the head to next node
		head = head->next;
		//step : free the temp
		free(temp);
		printf("\nDequeued %d from Queue Successfully!!",deleted_data); 
	}
	
}
int is_empty(){
	return (head==NULL); //return 1 if list is empty else 0
}
void peek_front(){
	if(is_empty()){
		printf("\nfront=NULL");
	}else{
		printf("\nfront=%d",head->data);	
	}
}
void peek_rear(){
	if(is_empty()){
		printf("\nrear=NULL");
	}else{
		printf("\nrear=%d",tail->data);	
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
		printf("\nMy Queue[ empty ]");
	}else{
		//traverse from front(head) till rear(tail)
		printf("\nMy Queue[");
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp = temp->next;
		}
		printf("null]");
	}
}

void free_list(){
	if(head!=NULL){ //if list is not empty then ONLY free all the nodes
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
