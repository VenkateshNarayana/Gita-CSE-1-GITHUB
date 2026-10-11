/*Dijkstra's algorithm finds the shortest distance from one source vertex to every other vertex 
	in a weighted graph, provided all edge weights are non-negative.
Algorithm
	1.Initialize the source vertex distance to 0.
	2.Initialize all other distances to INF (infinity).
	3.Select the unvisited vertex with the smallest known distance.
	4.Update the distances of its adjacent vertices if a shorter path is found.
	5.Mark the selected vertex as visited.
	6.Repeat until all reachable vertices have been processed.

The relaxation condition checks whether if by going through u gives a shorter path to v.
The key relaxation formula is:
	if 	dist[u] + weight(u,v) < dist[v]
   		dist[v]=dist[u]+weight(u,v)
*/
#include <stdio.h>

#define MAX 20
#define INF 99999

void dijkstra(int graph[MAX][MAX], int n, int src);

int main()
{
    int graph[MAX][MAX];
    int n, i, j, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)    {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter adjacency matrix (0 = no edge):\n");

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
            if (graph[i][j] < 0){
                printf("Negative weights are not allowed.\n");
                return 1;
            }
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);
    if (src < 0 || src >= n){
        printf("Invalid source vertex.\n");
        return 1;
    }

    dijkstra(graph, n, src);
    return 0;
}
void dijkstra(int graph[MAX][MAX], int n, int src)
{
    int dist[MAX];
    int visited[MAX] = {0};
    int i, count, u, v;
    int min;

    // Step 1: Initialize distances
    for (i = 0; i < n; i++){
        dist[i] = INF;
    }

    dist[src] = 0;

    // Step 2: Process vertices
    for (count = 0; count < n; count++){
        // Find the unvisited vertex with minimum distance
        min = INF;
        u = -1;

        for (i = 0; i < n; i++){
            if (!visited[i] && dist[i] < min){
                min = dist[i];
                u = i;
            }
        }

        // No more reachable vertices
        if (u == -1)
            break;

        // Mark the selected vertex as visited
        visited[u] = 1;

        // Step 3: Update distances of adjacent vertices
        for (v = 0; v < n; v++){
            if (!visited[v] &&
                graph[u][v] > 0 &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]){
                	
                dist[v] = dist[u] + graph[u][v];
        	}
        }
    }

    // Step 4: Display shortest distances
    printf("\nShortest distances from vertex %d:\n", src);

    for (i = 0; i < n; i++){
        if (dist[i] == INF)
            printf("%d -> %d : Unreachable\n", src, i);
        else
            printf("%d -> %d : %d\n", src, i, dist[i]);
    }
}
