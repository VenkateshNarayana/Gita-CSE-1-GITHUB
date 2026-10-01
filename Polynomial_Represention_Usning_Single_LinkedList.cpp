/* Polynomial Linked List - it is a linear data structure where elements are called nodes which are connected to each other using pointers.
   `			 These nodes are scattered in memory unlike elements of an array which are stored in contigous memory location.
   				 The node consists of 2 parts,
					1. data       - This stores the information of data(primitive,arrays,strings,user defined type)
					2. pointer    - This stores the address information of anothere node.
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	  int 			coeff;  //this is coefficient part1 of the term(information)
	  int           exp;    //this is exponent part1 of the term(information)
	  struct node* 	next;  //this is part2(pointer)
};


//creating a node
struct node* create_node(int,int); //param1 - to store the coeffiecint part1; param2- to store the exponent part

//insert
void insert_at_tail(struct node** head,struct node** tail, int coeff,int exp);

//perform polynomial addition
void polynomial_add(struct node* p_head,struct node* q_head);

//traverse
void traverse_list(struct node* head);
void free_list(struct node* head);

int main(){
	struct node* p_head = NULL;
	struct node* p_tail = NULL;
	
	//insert terms for p(x) at tail to build -> 5 X^2 + 3 X + 7 X^0
	insert_at_tail(&p_head,&p_tail,5,2);
//	traverse_list(p_head);
	insert_at_tail(&p_head,&p_tail,3,1);
//	traverse_list(p_head);
	insert_at_tail(&p_head,&p_tail,7,0);
	traverse_list(p_head);
	
	struct node* q_head = NULL;
	struct node* q_tail = NULL;
	//insert terms for q(x) at tail to build -> 10 X^3 + 4 X + 6 X^0
	insert_at_tail(&q_head,&q_tail,10,3);
//	traverse_list(q_head);
	insert_at_tail(&q_head,&q_tail,4,1);
//	traverse_list(q_head);
	insert_at_tail(&q_head,&q_tail,6,0);
	traverse_list(q_head);
	
	polynomial_add(p_head,q_head);
	
	free_list(p_head);  //this our clean up activity to prevent memory leaks
	free_list(q_head);  //this our clean up activity to prevent memory leaks
	
	return 0;
}
struct node* create_node(int coeff, int exp){  
	//param1 - input data to store the part1(data- which is information part)
	//use malloc to create the struct node
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node==NULL){
		printf("memory allocation failed.....");
		return NULL;
	}
	new_node->coeff = coeff;  //store the coefficient part of term
	new_node->exp   = exp;    //store the exponent part of term
	new_node->next  = NULL ;  //store NULL in the pointer part
	return new_node;
}
void insert_at_tail(struct node** head,struct node** tail,int coeff,int exp){
	//create a new node
	struct node* new_node = create_node(coeff,exp);
	
	if(new_node==NULL) return; //memory allocation failed
	if(*tail==NULL){
		//if linked list is empty then make the new node as head and tail
		*head = new_node;
		*tail = new_node;
	}else{
		//if linked list is NOT empty then point tail to the new node & move tail to new node
		(*tail)->next = new_node; //point tail to new node 
		*tail = new_node;       //move tail to new node
	}
	printf("\nInserted term(%d,%d) into polynomial Successfully!!",coeff,exp); 
}
void polynomial_add(struct node* p_head,struct node* q_head){
	struct node* res_head = NULL; 
	struct node* res_tail = NULL;
	int coeff=0, exp=0;
	while(p_head!=NULL && q_head!=NULL){
		//case1
		if(p_head->exp == q_head->exp){
			coeff = p_head->coeff + q_head->coeff;
			exp = p_head->exp;
			p_head = p_head->next; //move p to next node
			q_head = q_head->next; //move q to next node
		}else if(p_head->exp > q_head->exp){ //case2
			coeff = p_head->coeff;
			exp = p_head->exp;
			p_head = p_head->next; //move p to next node
		}else{//case3
		    coeff = q_head->coeff;
			exp = q_head->exp;
			q_head = q_head->next; //move q to next node
		}
		insert_at_tail(&res_head,&res_tail,coeff,exp); //appending the term to res list
	}	
	//any leftovers will be appended to res list
	while(p_head!=NULL){
		insert_at_tail(&res_head,&res_tail,p_head->coeff,p_head->exp); //appending the term to res list
		p_head = p_head->next; //move p to next node
	}
	while(q_head!=NULL){
		insert_at_tail(&res_head,&res_tail,q_head->coeff,q_head->exp); //appending the term to res list
		q_head = q_head->next; //move q to next node
	}
	traverse_list(res_head);
	free_list(res_head);
}
void traverse_list(struct node* head){
	struct node* temp;
	temp   =   head;
	printf("\nMy Polynomial list[ ");
	while(temp!=NULL){
		printf("%d X^%d",temp->coeff,temp->exp); //format 5 X^2
		temp = temp->next;
		if (temp!=NULL) printf(" + ");
	}
	
	printf(" ]");
}

void free_list(struct node* head){
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
