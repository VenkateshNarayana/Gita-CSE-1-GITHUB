/*deque(double ended queue) : Data management is done using a flexible operation where elements can be added and removed from both ends
  Operation    :1. enqueue_front --> insert the data from the front (using front index)
  			    2. enqueue_rear  --> insert the data from the rear (using front index and size)
				3. dequeue_front --> delete the data from the front (using front index)
  				4. dequeue_rear  --> delete the data from the rear (using front index and size)
				5. is_empty      --> size == 0
				6. is_full       --> size == MAX_SIZE
				7. traverse(size of the queue) -- traverse using for loop using circular index fromula i = (i+1) % SIZE
				8. peek_front --> Q[front]
				9. peek_rear  --> Q[rear]
*/
#include<stdio.h>
#define MAX_SIZE 5
int front = 0; // track front
int size  = 0; // track size and calculate rear using front and size
//enque operations
void enqueue_front(int[], int);//param1 = array name ;param2=value
void enqueue_rear(int[], int);//param1 = array name ;param2=value
//dequeue operations
int dequeue_front(int[]);      //param1 = array name
int dequeue_rear(int[]);      //param1 = array name
//underflow / overflow check
int is_empty();          //return 1 if (front == -1) else 0
int is_full();           //return 1 if (rear+1)%MAX_SIZE == frontelse 0
//traverse
void traverse(int[]);    //param1 = array name
//peek operations
int peek_front(int[]);   //param1 = array name
int peek_rear(int[]);    //param1 = array name

int main(){
	int queue[MAX_SIZE]={0};//create an array of size = MAX_SIZE and initialise it to 0
	//enqueue
	enqueue_front(queue,10);
	traverse(queue);
	enqueue_front(queue,20);
	traverse(queue);
	enqueue_rear(queue,30);
	traverse(queue);
	enqueue_front(queue,40);
	traverse(queue);
	enqueue_rear(queue,50);
	traverse(queue);
	
	enqueue_rear(queue,60);//will this work?NO because Q is full
	traverse(queue);
	
	printf("\nWho is in the front?%d",peek_front(queue));
	printf("\nWho is in the rear?%d",peek_rear(queue));
	
	//perform dequeue
	int dq_item = dequeue_front(queue);
	if (dq_item !=-1) printf("\nRemoved %d from the queue",dq_item);
	traverse(queue);
	
	enqueue_rear(queue,60);//will this work?YES because Q is circualar & we removed 1 item
	traverse(queue);
	
//	dq_item = dequeue(queue);
//	if (dq_item !=-1) printf("\nRemoved %d from the queue",dq_item);
//	traverse(queue);
//	
//	dq_item = dequeue(queue);
//	if (dq_item !=-1) printf("\nRemoved %d from the queue",dq_item);
//	traverse(queue);
//	
//	dq_item = dequeue(queue);
//	if (dq_item !=-1) printf("\nRemoved %d from the queue",dq_item);
//	traverse(queue);
//	
//	dq_item = dequeue(queue);
//	if (dq_item !=-1) printf("\nRemoved %d from the queue",dq_item);
//	traverse(queue);
//	
//	dq_item = dequeue(queue); //will this work? NO , because the Q is empty
//	if (dq_item !=-1) printf("\nRemoved %d from the queue",dq_item);
//	traverse(queue);
	
	return 0; //for main()
}
int is_full(){
	return (size==MAX_SIZE); //return 1 if full else 0 
}
int is_empty(){
	return(size==0);        //return 1 if empty else 0
}
void enqueue_front(int q[], int value){//param1 = array name ;param2=value
	if(is_full()){
		printf("\nQ overflow..cannot enqueue %d value",value);
	}else{
		//enqueue
		front = (front-1+MAX_SIZE) % MAX_SIZE; //my index formula
		q[front] = value;
		size++; //increment the current size by 1
	}
}
void enqueue_rear(int q[], int value){//param1 = array name ;param2=value
	if(is_full()){
		printf("\nQ overflow..cannot enqueue %d value",value);
	}else{	
		//enqueue
		int rear = (front + size) % MAX_SIZE;
		q[rear]  = value;
		size++; //increment the current size by 1
	}
}
int dequeue_front(int q[]){      //param1 = array name
	int dq_item = -1;
	if(is_empty()){
		printf("\nQ underflow..cannot perform dequeu");
	}else{
		dq_item = q[front];
		front = (front + 1) % MAX_SIZE;
		size--;
	}
	return dq_item;
}
int dequeue_rear(int q[]){      //param1 = array name
	int dq_item = -1;
	if(is_empty()){
		printf("\nQ underflow..cannot perform dequeu");
	}else{
		int rear = (front + size - 1) % MAX_SIZE;
		dq_item = q[rear];
		size--;
	}
	return dq_item;
}
void traverse(int q[]){
	//Also print the current size
	if(is_empty()){
		printf("\nQ (CURR SIZE= 0)-->[ empty ]");
	}else{
		printf("\nQ (CURR SIZE=%d)-->[",size);
		int index;
		for(int i=0;i<size;i++){
			index = (front + i) % MAX_SIZE;
			printf("%d ",q[index]);
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
	int rear = (front+size-1) % MAX_SIZE;
	return (q[rear]);  ////return whatever is available in rear
}

