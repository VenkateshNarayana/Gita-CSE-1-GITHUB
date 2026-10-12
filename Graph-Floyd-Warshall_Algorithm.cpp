/*Given a matrix dist[][] of size n x n, where dist[i][j] represents the weight of the edge from node i to node j.
	a.If there is no direct edge, dist[i][j] is set to INF (a large value i.e., 10^8).
	b.The diagonal entries dist[i][i] are 0, since the distance from a node to itself is zero.
	c.The graph may contain negative edge weights, but it does not contain any negative weight cycles.
Determine the shortest path distance between all pair of nodes in the graph.

Algorithm
	1. Start by updating the distance matrix by treating each vertex as a possible intermediate node between 
	all pairs of vertices.
	2.Iterate through each vertex, one at a time. For each selected vertex k, attempt to improve the shortest paths 
	that pass through it.
	3.When we pick vertex number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1} 
	as intermediate vertices. 
	4.For every pair (i, j) of the source and destination vertices respectively, there are two possible cases. 
		a.k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is. 
		b.k is an intermediate vertex in shortest path from i to j. We update the value of 
		    dist[i][j] as dist[i][k] + dist[k][j], if dist[i][j] > dist[i][k] + dist[k][j]
	7.Repeat this process for each vertex k until all intermediate possibilities have been considered.

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
