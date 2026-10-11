/* Graph
Operations - insert
			 delete
			 traverse - preorder, inorder, postorder
			 search
  0----1
  |    |
  |    |
  3----2	
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 4
struct vertex{
	int data;
	struct vertex* next;
};
struct vertex* adjList[MAX]={NULL};
struct vertex* create_vertex(int data);
void add_edge(int src,int dest);
void display_graph();
void free_graph();
void dfs(int start_vertex);
void bfs(int start_vertex);

int main(){
	 /* Initialize adjacency list */
    for (int i = 0; i < MAX; i++){
        adjList[i] = NULL;
    }
	//create edges list
	add_edge(0,1);
	add_edge(0,3);
	add_edge(1,2);
	add_edge(2,3);
	
	display_graph(); //adjacency list
	
	dfs(0);
	bfs(0);
	
	free_graph();    //free graph
	return 0; //main
	
}
struct vertex* create_vertex(int data){
	struct vertex* new_vertex = (struct vertex*) malloc(sizeof(struct vertex));
	if (new_vertex==NULL){
		printf("\nmemory allocation failed..");
		return NULL;
	}
	new_vertex->data = data;
	new_vertex->next = NULL;
	
	return new_vertex;	
}

void add_edge(int src,int dest){
	struct vertex* new_vertex;
	
	//create the src to dest link
	new_vertex       = create_vertex(dest);
	if (new_vertex==NULL) return; //malloc failed
	new_vertex->next = adjList[src];
	adjList[src]     = new_vertex;
	
	//create the dest to src link as well(for undirected graph)
	new_vertex       = create_vertex(src);
	if (new_vertex==NULL) return; //malloc failed
	new_vertex->next = adjList[dest];
	adjList[dest]    = new_vertex;

}
void dfs(int start_vertex){
	int top = -1;
	int visited[MAX]={0};//make all the vertex as not visited=0
	int stack[MAX] = {0};
	struct vertex* temp = NULL;
	int vertex, adjacent;
	
	//push the starting vertex into stack
	stack[++top] = start_vertex;
	//mark the vertex as visited
	visited[start_vertex] = 1;
	
	
	printf("\nDFS-PATH->");
	while(top!=-1){//while stack is not empty
		//pop the vertex from top
		int vertex = stack[top--];
		printf("%d ",vertex);
		
		//traverse to adjacent nodes
		temp = adjList[vertex];
		while(temp!=NULL){
			//check adjacent is visited or not
			adjacent = temp->data;
			if(visited[adjacent]==0) {
				//push the adjacent vertex into stack
				stack[++top] = adjacent;
				//mark the vertex as visited
				visited[adjacent] = 1;
			}
			temp = temp->next; //traverse to next adjacent vertex
		}
	}
	//traversal complete
	printf("\n********************");
}
void bfs(int start_vertex){
	int front =  0;
	int rear  = -1;
	int visited[MAX]={0};//make all the vertex as not visited=0
	int q[MAX] = {0};
	struct vertex* temp = NULL;
	int vertex, adjacent;
	
	//enque the starting vertex into queue
	q[++rear] = start_vertex;
	//mark the vertex as visited
	visited[start_vertex] = 1;
	
	printf("\nBFS-PATH->");
	while(front<=rear){//while queue is not empty
		//deque the vertex in front
		int vertex = q[front++];
		printf("%d ",vertex);
		
		//traverse to adjacent vertices
		temp = adjList[vertex];
		while(temp!=NULL){
			//check adjacent is visited or not
			adjacent = temp->data;
			if(visited[adjacent]==0) {
				//enqueue the adjacent vertex into queue
				q[++rear] = adjacent;
				//mark the vertex as visited
				visited[adjacent] = 1;
			}
			temp = temp->next; //traverse to next adjacent vertex
		}
	}
	//traversal complete
	printf("\n********************");
}
void display_graph(){
	struct vertex* temp=NULL;
	printf("Adjacency List:\n");
	for(int i=0;i<MAX;i++){
		temp = adjList[i]; //start from 0
		printf("\n%d -> ", i);
		while(temp!=NULL){
			printf("%d ->",temp->data);
			temp = temp->next;
		}
		printf("NULL");
	}
	printf("\n**********************");
}
void free_graph(){
	struct vertex* temp=NULL;
	struct vertex* head=NULL;
	
	for(int i=0;i<MAX;i++){
		temp = adjList[i]; //start from 0
		head = temp;

		while(head!=NULL){
			temp = head;
			head = head->next;
			free(temp);
		}
		adjList[i] = NULL; //make this dangling pointer to NULL pointer
	}
	printf("\nfreed all adjacency list of graph successfully!!");
}
