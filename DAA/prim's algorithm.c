#include <stdio.h> 
#include <stdlib.h> 

#define V 5   // Number of vertices in graph

// Function to find the vertex with minimum key value
int minKey(int key[], int visited[]) 
{ 
    int min = 999999;   // Initialize minimum value (infinity)
    int min_index = 0; 

    // Loop to find smallest key value from unvisited vertices
    for (int i = 0; i < V; i++) 
    { 
        if (!visited[i] && key[i] < min) 
        { 
            min = key[i]; 
            min_index = i; 
        } 
    } 
    return min_index;   // Return index of minimum key vertex
} 

// Function to print the MST
void printPrimMST(int parent[], int graph[V][V]) 
{ 
    printf("\nPrim's MST:\n"); 
    printf("Edge \tWeight\n"); 

    int total = 0;   // To calculate total cost

    // Print edges and their weights
    for (int i = 1; i < V; i++) 
    { 
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]); 
        total += graph[i][parent[i]];   // Add weight to total
    } 

    printf("Total Cost = %d\n", total); 
} 

// Function to implement Prim's Algorithm
void primMST(int graph[V][V]) 
{ 
    int parent[V];   // Array to store constructed MST
    int key[V];      // Key values to pick minimum weight edge
    int visited[V];  // To track visited vertices

    // Initialize all keys as infinite and visited as false
    for (int i = 0; i < V; i++) 
    { 
        key[i] = 999999; 
        visited[i] = 0; 
    } 

    key[0] = 0;        // Start from first vertex
    parent[0] = -1;    // First node is root of MST

    // Loop to construct MST
    for (int count = 0; count < V - 1; count++) 
    { 
        int u = minKey(key, visited);  // Pick minimum key vertex
        visited[u] = 1;                // Mark it as visited

        // Update key and parent for adjacent vertices
        for (int v = 0; v < V; v++) 
        { 
            // Condition: edge exists, vertex not visited, and weight is smaller
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) 
            { 
                parent[v] = u;           // Set parent
                key[v] = graph[u][v];    // Update key value
            } 
        } 
    } 

    // Print the final MST
    printPrimMST(parent, graph); 
} 

int main() 
{ 
    // Graph represented using adjacency matrix
    int graph[V][V] =
    { 
        {0, 2, 3, 0, 0}, 
        {2, 0, 5, 3, 0}, 
        {3, 5, 0, 0, 4}, 
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0},
    };  

    // Call Prim's algorithm function
    primMST(graph); 

    return 0; 
}
