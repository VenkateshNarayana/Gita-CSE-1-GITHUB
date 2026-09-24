/* Linked List - it is a linear data structure where elements are called nodes which are connected to each other using pointers.
   `			 These nodes are scattered in memory unlike elements of an array which are stored in contigous memory location.
   				 The node consists of 2 parts,
					1. data       - This stores the information of data(primitive,arrays,strings,user defined type)
					2. pointer    - This stores the address information of anothere node.
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
void insert_at_head(int input_data);
void insert_at_tail(int input_data);

//delete
void delete_at_head();
void delete_at_tail();


//traverse
void traverse_list();
void free_list();

int main(){
	
	//insert operations - at head
	insert_at_head(10);
	traverse_list();
	insert_at_head(20);
	traverse_list();
	
	//insert operations - at tail
	insert_at_tail(30);
	traverse_list();
	insert_at_tail(50);
	traverse_list();
	
	//delete operations - at head
	delete_at_head();
	traverse_list();
	
	//delete operations - at tail
	delete_at_tail();
	traverse_list();
	
	free_list();  //this our clean up activity to prevent memory leaks
	return 0;
}
void insert_at_head(int input_data){
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
	printf("\nInserted %d(at head) into linked list Successfully!!",input_data); 
}
void insert_at_tail(int input_data){
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
	printf("\nInserted %d (at tail)into linked list Successfully!!",input_data); 
}
void delete_at_head(){
	if(head==NULL){
		//linked is empty
		printf("\nLinked list is empty..cannot perform delete operation!!");
	}else{
		//step1 : store the address of head into temp
		struct node* temp = head;
		int deleted_data = head->data;
		//step2 : move the head to next node
		head = head->next;
		//step : free the temp
		free(temp);
		printf("\nDeleted %d from linked list Successfully!!",deleted_data); 
	}
	
}
void delete_at_tail(){
	if(head==NULL){
		//linked is empty
		printf("\nLinked list is empty..cannot perform delete operation!!");
	}else{
		//step1 : store the address of head into temp
		struct node* temp_tail = tail; //store the old tail in temp_tail
		int deleted_data = tail->data;
		
		//step1 : traverse upto one node before tail
		struct node* temp= head;
		while(temp->next!=tail){
			temp = temp->next; //move to next node
		}
		//you are at 1 node before tail
		//step2 : make this as your tail by storing NULL in its next
		temp->next = NULL;
		
		//step3 : move the tail to this new tail(temp)
		tail = temp;
		//step4 : free the temp_tail(old tail)
		free(temp_tail);
		printf("\nDeleted %d from linked list Successfully!!",deleted_data); 
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
void traverse_list(){
	struct node* temp;
	temp=head;
	printf("\nMy Linked list[");
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("null]");
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
