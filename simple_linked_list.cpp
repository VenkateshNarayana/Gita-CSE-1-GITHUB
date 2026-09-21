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
 
int main(){
	struct node node1, node2, node3 , node4;
	//lets create a simple linked list by filling the data and pointer information for each node
	
	//head node
	node1.data = 10;
	node1.next = &node2 ; //address of node2 using the address of operator(&)
	
	node2.data = 20;
	node2.next = &node3; //address of node3
	
	node3.data = 30;
	node3.next = &node4; //address of node4
	
	//tail node
	node4.data = 40;
	node4.next = NULL; //do not store any address because it is the end of linked list
	
	//traverse from head to tail
	printf("Simple Linked list[");
	printf("%d->",node1.data); //print 10
	printf("%d->",node1.next->data); //print node2 data = 20
	printf("%d->",node1.next->next->data); //print node3 data = 30
	printf("%d->",node1.next->next->next->data); //print node4 data = 40(tail) end of linked list
	printf("null ]\n");
	
	struct node* temp;
	temp = &node1;
	printf("\nMy Linked list[");
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("null]");	
	return 0;
}
