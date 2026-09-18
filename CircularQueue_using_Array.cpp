/*Circular Queue : Data management is done using the principle FIFO (first in first out)
  Operation   :1. enqueue --> populate the data using circular index formula rear = (rear + 1)% MAX_SIZE  Q[rear]=value
  				2. dequeue --> front = (front + 1)% MAX_SIZE or dq_item = Q[front]
				3. is_empty --> front == -1
				4. is_full --> (rear+1)%MAX_SIZE == front
				5. traverse(size of the queue) --traverse using for loop using circular index fromula i = (i+1) % SIZE
				6. peek_front --> Q[front]
				7. peek_rear  --> Q[rear]
*/
#include<stdio.h>
#define MAX_SIZE 5
int front = -1; // track front
int rear  = -1; // track rear

void enqueue(int[], int);//param1 = array name ;param2=value
int dequeue(int[]);      //param1 = array name
int is_empty();          //return 1 if (front == -1) else 0
int is_full();           //return 1 if (rear+1)%MAX_SIZE == frontelse 0
void traverse(int[]);    //param1 = array name
int peek_front(int[]);   //param1 = array name
int peek_rear(int[]);    //param1 = array name

int main(){
	int queue[MAX_SIZE]={0};//create an array of size = MAX_SIZE and initialise it to 0
	//enqueue
	enqueue(queue,10);
	traverse(queue);
	enqueue(queue,20);
	traverse(queue);
	enqueue(queue,30);
	traverse(queue);
	enqueue(queue,40);
	traverse(queue);
	enqueue(queue,50);
	traverse(queue);
	
	enqueue(queue,60);//will this work?NO because Q is full
	traverse(queue);
	
	printf("\nWho is in the front?%d",peek_front(queue));
	printf("\nWho is in the rear?%d",peek_rear(queue));
	
	//perform dequeue
	int dq_item = dequeue(queue);
	if (dq_item !=-1) printf("\nRemoved %d from the queue",dq_item);
	traverse(queue);
	
//	enqueue(queue,60);//will this work?YES because Q is circualar & we removed 1 item
//	traverse(queue);
	
	dq_item = dequeue(queue);
	if (dq_item !=-1) printf("\nRemoved %d from the queue",dq_item);
	traverse(queue);
	
	dq_item = dequeue(queue);
	if (dq_item !=-1) printf("\nRemoved %d from the queue",dq_item);
	traverse(queue);
	
	dq_item = dequeue(queue);
	if (dq_item !=-1) printf("\nRemoved %d from the queue",dq_item);
	traverse(queue);
	
	dq_item = dequeue(queue);
	if (dq_item !=-1) printf("\nRemoved %d from the queue",dq_item);
	traverse(queue);
	
	dq_item = dequeue(queue); //will this work? NO , because the Q is empty
	if (dq_item !=-1) printf("\nRemoved %d from the queue",dq_item);
	traverse(queue);
	
	return 0; //for main()
}
int is_full(){
	return ((rear+1) % MAX_SIZE==front); //return 1 if full else 0 
}
int is_empty(){
	return(front==-1);        //return 1 if empty else 0
}
void enqueue(int q[], int value){//param1 = array name ;param2=value
	if(is_full()){
		printf("\nQ overflow..cannot enqueue %d value",value);
	}else{
		//enqueue
		if(front==-1){
			front = 0;
			rear  = 0;
		}else{
			rear = (rear+1)	% MAX_SIZE;
		}
		q[rear]=value;
	}
}
int dequeue(int q[]){      //param1 = array name
	int dq_item = -1;
	if(is_empty()){
		printf("\nQ underflow..cannot perform dequeu");
	}else{
		dq_item = q[front];
		if(front==rear){ //reset the queue
			front =  -1;
			rear  = -1;
		}else{
			front = (front+1) % MAX_SIZE;	
		}
	}
	return dq_item;
}

void traverse(int q[]){
	//Also print the current size
	if(is_empty()){
		printf("\nQ (CURR SIZE=0) front=-1,rear=-1-->[ empty ]");
		
	}else{
		int size = (rear >= front) ? (rear - front + 1) : (MAX_SIZE - (rear - front + 1));
		printf("\nQ (CURR SIZE=%d) front=%d,rear=%d-->[",size,q[front],q[rear]);
		int i = front;
		while(1){
			printf("%d ",q[i]);	
			if (i==rear) break;
			i = (i+1) % MAX_SIZE;
		}
		printf("]");
	}
}
int peek_front(int q[]){   //param1 = array name
	if (is_empty()){
		return -1;
	}
	return (q[front]); //return whatever is available in front
}
int peek_rear(int q[]){    //param1 = array name
	if (is_empty()){
		return -1;
	}
	return (q[rear]);  ////return whatever is available in rear
}

