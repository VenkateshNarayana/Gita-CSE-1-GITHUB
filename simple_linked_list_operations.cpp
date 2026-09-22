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
//traverse
void traverse_list();
int main(){
	insert_at_head(10);
	traverse_list();
	insert_at_head(20);
	traverse_list();
	
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
