/*Dijkstra's algorithm finds the shortest distance from one source vertex to every other vertex 
	in a weighted graph, provided all edge weights are non-negative.
Algorithm
	1.Initialize the source vertex distance to 0.
	2.Initialize all other distances to INF (infinity).
	3.Select the unvisited vertex with the smallest known distance.
	4.Update the distances of its adjacent vertices if a shorter path is found.
	5.Mark the selected vertex as visited.
	6.Repeat until all reachable vertices have been processed.

At every iteration, the algorithm checks whether the path from i to j becomes shorter by 
passing through k.

D[i][j]   =  min(D[i][j]  ,   D[i][k]+D[k][j])

Example 1:
Input : 4
0     	5  		99999    10
99999 	0     	3 		 99999
99999 	99999 	0     	 1
99999 	99999 	99999 	 0


All-Pairs Shortest Distance Matrix:

      0      5      8      9
    INF      0      3      4
    INF    INF      0      1
    INF    INF    INF      0

No negative-weight cycle detected.

Example 2:
Input : 4
0     	8  		99999    1
99999 	0     	1 		 99999
4	 	99999 	0     	 99999
99999 	2 		9	 	 0


All-Pairs Shortest Distance Matrix:

      0      3      4      1
      5      0      1      6
      4      7      0      5
      7      2      3      0
*/

#include <stdio.h>

#define MAX 20
#define INF 99999

void floyd_warshall(int graph[MAX][MAX], int n);

int main()
{
    int graph[MAX][MAX];
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX){
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("\nEnter the adjacency matrix:\n");
    printf("Use %d for INF (no edge).\n", INF);

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    floyd_warshall(graph, n);

    return 0;
}
void floyd_warshall(int graph[MAX][MAX], int n)
{
    int dist[MAX][MAX];
    int i, j, k;

    // Step 1: Initialize the distance matrix
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            dist[i][j] = graph[i][j];
        }
    }

    // Step 2: Consider each vertex as an intermediate vertex
    for (k = 0; k < n; k++){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                // Avoid adding infinity values
                if (dist[i][k] != INF &&
                    dist[k][j] != INF){
                    if (dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] =
                            dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Step 3: Display all-pairs shortest distances
    printf("\nAll-Pairs Shortest Distance Matrix:\n\n");

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }

        printf("\n");
    }

    // Step 4: Detect a negative-weight cycle
    for (i = 0; i < n; i++){
        if (dist[i][i] < 0){
            printf("\nNegative-weight cycle detected!\n");
            return;
        }
    }

    printf("\nNo negative-weight cycle detected.\n");
}
