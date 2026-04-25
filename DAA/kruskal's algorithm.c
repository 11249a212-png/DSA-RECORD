#include <stdio.h> 

#define V 5   // Number of vertices
#define E 6   // Number of edges

int parent[V];   // Array to store parent of each vertex (for union-find)

// Function to find the leader (root) of a set
int findLeader(int v) 
{ 
    // Traverse until we reach the root
    while (parent[v] != v) 
        v = parent[v]; 
    return v; 
} 

// Function to merge two sets
void mergeSets(int u, int v) 
{ 
    int a = findLeader(u);   // Find root of u
    int b = findLeader(v);   // Find root of v

    parent[a] = b;   // Make one root as parent of another
} 

// Function to sort edges based on weight (Bubble Sort)
void sortEdges(int edges[E][3]) 
{ 
    for (int i = 0; i < E - 1; i++) 
    { 
        for (int j = 0; j < E - i - 1; j++) 
        { 
            // Compare weights
            if (edges[j][2] > edges[j + 1][2]) 
            { 
                // Swap entire edge (u, v, w)
                for (int k = 0; k < 3; k++) 
                { 
                    int temp = edges[j][k]; 
                    edges[j][k] = edges[j + 1][k]; 
                    edges[j + 1][k] = temp; 
                } 
            } 
        } 
    } 
} 

// Function to implement Kruskal's Algorithm
void kruskal(int edges[E][3]) 
{ 
    sortEdges(edges);   // Step 1: Sort edges by weight

    // Initialize each vertex as its own parent
    for (int i = 0; i < V; i++) 
        parent[i] = i; 

    int count = 0, cost = 0; 

    printf("Selected Edges:\n"); 

    // Step 2: Pick edges one by one
    for (int i = 0; i < E; i++) 
    { 
        int u = edges[i][0];   // Start vertex
        int v = edges[i][1];   // End vertex
        int w = edges[i][2];   // Weight

        // Check if including this edge forms a cycle
        if (findLeader(u) != findLeader(v)) 
        { 
            printf("%d -- %d (Weight: %d)\n", u, v, w); 

            mergeSets(u, v);   // Merge the sets
            cost += w;         // Add weight to total cost
            count++; 
        } 

        // Stop when MST has V-1 edges
        if (count == V - 1) 
            break; 
    } 

    printf("Total Cost: %d\n", cost); 
} 

int main() 
{ 
    // Edge list: {source, destination, weight}
    int edges[E][3] = { 
        {0, 1, 2}, {0, 2, 3}, {1, 2, 5}, 
        {1, 3, 3}, {2, 4, 4}, {3, 4, 2}
    }; 

    // Call Kruskal's algorithm
    kruskal(edges); 

    return 0; 
}
