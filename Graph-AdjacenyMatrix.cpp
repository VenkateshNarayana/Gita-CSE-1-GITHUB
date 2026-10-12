#include <stdio.h>
#define MAX 4

/* Initialize matrix */
int graph[MAX][MAX] ={ {0,1,0,1},
    				   {1,0,1,0},
    				   {0,1,0,1},
    				   {1,0,1,0}
        		  	};
/* Display Adjacency Matrix */	
void display_matrix();

/* DFS using recursion*/
void DFS(int start);

/* DFS using stack*/
void DFS_using_stack(int start);

/* BFS */
void BFS(int start);

int main()
{
    int i;
    int start;

    /* Display matrix */
    display_matrix();


    /* DFS */
    printf("\nEnter starting vertex for DFS: ");
    scanf("%d", &start);
    printf("DFS Traversal: ");

//    DFS(start, visited);
	DFS_using_stack(start);

    /* BFS */
    printf("\n\nEnter starting vertex for BFS: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");

    BFS(start);


    printf("\n");

    return 0;
}
/* Display adjacency matrix */
void display_matrix(){
    int i, j;

    printf("\nAdjacency Matrix:\n\n");
    printf("   ");

    for (i = 0; i < MAX; i++)
        printf("%d ", i);

    printf("\n");

    for (i = 0; i < MAX; i++){
        printf("%d  ", i);
        for (j = 0; j < MAX; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

/* DFS */
void DFS(int start){

    int visited[MAX] = {0};
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < MAX; i++){
        if (graph[start][i] == 1 && visited[i] == 0){
            DFS(i);
        }
    }
}

/* DFS */
void DFS_using_stack(int start){

	int stack[MAX]={0};
	int top=-1;
	int visited[MAX] = {0};
	    
    visited[start] = 1;
	//push vertex into stack
	stack[++top] = start;
	while(top!=-1){//stack is not empty
		//pop stack
		start = stack[top--];
		printf("%d ", start); //pop
		
	    /* Find all adjacent vertices & push them to stack*/
	    for (int i = MAX-1; i >= 0; i--){ //traverse from last
	        if (graph[start][i] == 1 && visited[i] == 0){
	            stack[++top] = i; //push any unvisited vertice into stack
	            visited[i] = 1;   //mark it visited
	        }
	    }
	}
}


/* BFS */
void BFS(int start)
{
    int queue[MAX];
    int visited[MAX] = {0};

    int front = 0;
    int rear = -1;

    int vertex;
    int i;

    /* Insert starting vertex */
    queue[++rear] = start;
    visited[start] = 1;

    while (front <= rear)
    {
        /* Remove vertex from queue */
        vertex = queue[front++];

        printf("%d ", vertex);

        /* Find all adjacent vertices */
        for (i = 0; i < MAX; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0){
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

