/* Double Linked List -
  The node consists of 3 parts,
					1. data       - This stores the information of data(primitive,arrays,
					                strings,user defined type)
					2. pointer    - This stores the address information of next node.
					3. pointer    - This stores the address information of previous node.
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	  int 			data;  //this is part1(information)
	  struct node* 	next;  //this stores address of next pointer
	  struct node* 	prev;  //this stores address of previous node
};
struct node* head = NULL;
struct node* tail = NULL;

//creating a node
struct node* create_node(int); //param1 - input data to store the part1(data- which is information part)

//insert
void insert_at_head(int input_data);
void insert_at_tail(int input_data);
void insert_at_position(int node_value,int input_data); //param1=where to insert ; param2=what value to insert;

//delete
void delete_at_head();
void delete_at_tail();
void delete_at_position(int node_value);

//traverse
void traverse_head();
void traverse_tail();

void free_list();

int main(){
	
	//insert operations - at head
	insert_at_head(10);
//	traverse_head();
//	traverse_tail();
	insert_at_head(20);
//	traverse_head();
//	traverse_tail();
	
	//insert operations - at tail
	insert_at_tail(30);
//	traverse_head();
//	traverse_tail();
	insert_at_tail(50);
//	traverse_head();
//	traverse_tail();
	
	
	//insert operation  - at position (before node 50)
	insert_at_position(50,45);
	traverse_head();
	traverse_tail();
	
	//first position
	insert_at_position(10,5);
	traverse_head();
	traverse_tail();
	
	//negative case
	insert_at_position(1000,1005);
	traverse_head();
	traverse_tail();
	
	//delete operations - at head
	delete_at_head();
	traverse_head();
	traverse_tail();
	
	//delete operations - at tail
	delete_at_tail();
	traverse_tail();
	traverse_head();
	
	//delete operations - at tail
	delete_at_tail();
	traverse_tail();
	traverse_head();
	
	//delete operations - at position
	delete_at_position(10);
	traverse_tail();
	traverse_head();
	delete_at_position(50);
	traverse_tail();
	traverse_head();
	delete_at_position(20);
	traverse_tail();
	traverse_head();
	free_list();  //this our clean up activity to prevent memory leaks
	return 0;
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
	new_node->next = NULL ;      //store NULL in the next pointer
	new_node->prev = NULL ;      //store NULL in the previous pointer 
	
	return new_node;
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
		head->prev = new_node; //point current head's previous node to new node
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
		new_node->prev = tail; //point the new node to tail first 
		tail = new_node;       //next move the tail to new node
	}
	printf("\nInserted %d (at tail)into linked list Successfully!!",input_data); 
}
void insert_at_position(int node_value,int input_data){
	if(head==NULL){
		printf("\nList is empty..cannot find the position(%d)!!",node_value);
	}else if (head->data==node_value){
		insert_at_head(input_data);
	}else{
		//step 1: search for the node_value
		struct node* temp = head;
		while(temp->next!=NULL){
			if (temp->next->data==node_value) break;
			temp = temp->next; //move to next node and check for node value
		}
		if (temp->next==NULL){
			printf("\nCannot find the node(%d) in the list!!",node_value);
		}else{
			//temp is now 1 node before the position
			struct node* new_node = create_node(input_data);
			if(new_node==NULL) return; //memory allocation failed dont proceed
			//step1 :new node's next point to temp's next
			new_node->next = temp->next;
			//step2 :new node's previous point to temp
			new_node->prev = temp;
			//step3 : temp's next point to new node
			temp->next = new_node;
			//step4 : new node's next node's prev point to new node
			struct node* next_node = new_node->next;
			next_node->prev = new_node;  
			printf("\nInserted %d at position(%d) of list Successfully!!",input_data,node_value); 
		}
		
	}
}

void delete_at_head(){
	if(head==NULL){
		//linked is empty
		printf("\nLinked list is empty..cannot perform delete operation!!");
	}else if(head->next==NULL){
		//single node - free the node after making head and tail NULL
		struct node* temp = head;
		int deleted_data = head->data;
		head = tail = NULL; //set head and tail to NULL
		free(temp);         //free temp
		printf("\nDeleted %d from head of linked list Successfully!!",deleted_data);	
	}else{
		//step1 : store the address of head into temp
		struct node* temp = head;
		int deleted_data = head->data;
		//step2 : move the head to next node
		head = head->next;
		head->prev = NULL; //set the previous node to NULL (as this is my first node)
		//step : free the temp
		free(temp);
		printf("\nDeleted %d from head of linked list Successfully!!",deleted_data); 
	}
}
void delete_at_tail(){
	if(tail==NULL){
		//linked is empty
		printf("\nLinked list is empty..cannot perform delete operation!!");
	}else if(head->next==NULL){
		//single node - free the node after making head and tail NULL
		struct node* temp = tail;
		int deleted_data = tail->data;
		head = tail = NULL; //set head and tail to NULL
		free(temp);         //free temp
		printf("\nDeleted %d from head of linked list Successfully!!",deleted_data);	
	}else{
		//step1 : traverse upto one node before tail
		struct node* temp= tail; //store the tail
		int deleted_data = tail->data;
		
		//step2 : move the tail to previous node because that is our new tail
		tail = tail->prev;
		tail->next = NULL; //storing NULL in its next as it is my last node
		//step3 : free the temp(old tail)
		free(temp);
		printf("\nDeleted %d from tail of linked list Successfully!!",deleted_data); 
	}
}
void delete_at_position(int node_value){
	
	if(head==NULL){
		printf("\nList is empty..cannot find the position(%d)!!",node_value);
	}else if (head->data==node_value){
		delete_at_head();
	}else if (tail->data==node_value){
		delete_at_tail();
	}else{
		//step 1: search for the node_value
		struct node* temp = head;
		//search for the delete node 
		//approach 2 -> go directly to node to be deleted and mark it deleted node and node find one before node
		while(temp!=NULL){
			if(temp->data==node_value) break;
			temp = temp->next;
		}
		if (temp==NULL){
			printf("\nCannot find the node(%d) in the list!!",node_value);
		}else{
			//if node is found then perform the deletion
			struct node* next_node   = temp->next; //next of deleted node
			struct node* prev_node   = temp->prev; //previous of deleted node
			
			//step 2: point prev node's next to next node
			prev_node->next = next_node; //store the temp->next's address in new node's next 
			
			//step 3: point next node's previous to prev_node
			next_node->prev = prev_node; //point the next node's previous to temp
			
			free(temp); //free the delete node(temp)
			printf("\nDeleted node(%d) from position Successfully!!",node_value);
		}
	}
}

void traverse_head(){
	struct node* temp=NULL;
	if (head==NULL){
		printf("\nList(head->tail)[empty list]");
	}else{
		temp = head; //initialize to head
		printf("\nList(head->tail)[");
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp = temp->next; //move to next node
		}
		printf("null]\n");
	}
}
void traverse_tail(){
	struct node* temp=NULL;
	if (tail==NULL){
		printf("\nList(tail->head)[empty list]");
	}else{
		temp = tail; //initialize to tail
		printf("\nList(tail->head)[");
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp = temp->prev; //move to previous node
		}
		printf("null]\n");
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
