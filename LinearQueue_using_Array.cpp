/*Linear Queue : Data management is done using the principle FIFO (first in first out)
  Operartion   :1. enqueue --> rear = rear + 1 or Q[++rear]=value
  				2. dequeue --> front = front + 1 or dq_item = Q[front++]
				3. is_empty --> front>rear
				4. is_full --> rear = MAX_SIZE -1
				5. traverse(size of the queue) --traverse using for loop where i = front ; i<= rear ; i++
				6. peek_front --> Q[front]
				7. peek_rear  --> Q[rear]
				
*/
#include<stdio.h>
#define MAX_SIZE 5
int front =  0; //you can use -1 also but to avoid initializing it to 0 during enque we set it 0
int rear  = -1;

void enqueue(int[], int);//param1 = array name ;param2=value
int dequeue(int[]);      //param1 = array name
int is_empty();          //return 1 if front>rear else 0
int is_full();           //return 1 if rear = MAX_SIZE - 1 else 0
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
	return (rear==MAX_SIZE-1); //return 1 if rear = MAX_SIZE - 1 else 0 
}
int is_empty(){
	return(front>rear);        //return 1 if front>rear else 0
}
void enqueue(int q[], int value){//param1 = array name ;param2=value
	if(is_full()){
		printf("\nQ overflow..cannot enqueue %d value",value);
	}else{
		//enqueue
		q[++rear]=value;
	}
}
int dequeue(int q[]){      //param1 = array name
	int dq_item = -1;
	if(is_empty()){
		printf("\nQ underflow..cannot perform dequeu");
	}else{
//		int dq_item = q[front++];
		dq_item = q[front];
		front = front + 1;
		if(front>rear){ //reset the queue
			front =  0;
			rear  = -1;
		}
	}
	return dq_item;
}

void traverse(int q[]){
	//Also print the current size
	printf("\nQ (CURR SIZE=%d) front=%d,rear=%d-->[",(rear+1-front),rear,front);
	for (int i=front; i<=rear;i++){
		printf("%d ",q[i]);	
	}
	printf("]");
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

