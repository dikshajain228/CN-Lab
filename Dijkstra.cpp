#include<bits/stdc++.h>
using namespace std;
 
#define V 5

// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool visited[]) 
{ 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (visited[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

int printSolution(int dist[]) 
{ 
	printf("Vertex \t\t Distance from Source\n"); 
	for (int i = 0; i < V; i++) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

void dijkstra(int graph[V][V], int src) 
{ 
	int dist[V]; 
	bool visited[V]; 
	
	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		visited[i] = false; 
	}
		

	dist[src] = 0; 

	for (int count = 0; count < V - 1; count++) { 
		// Pick the minimum distance vertex from the set of vertices not 
		// yet processed. u is always equal to src in the first iteration. 
		int u = minDistance(dist, visited); 

		visited[u] = true; 

		// Update dist value of the adjacent vertices of the picked vertex. 
		for (int v = 0; v < V; v++) 

			// Update dist[v] only if is not in visited, there is an edge from 
			// u to v, and total weight of path from src to v through u is 
			// smaller than current value of dist[v] 
			if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 

	printSolution(dist); 
} 

int main() 
{ 
	int graph[V][V] ;
	int i,j;
	
	cout<<"enter the graph"<<endl;
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			cin>>graph[i][j];
		}
	}

	dijkstra(graph, 0); 

	return 0; 
} 
