#include <iostream>
#include <climits>

using namespace std;

// Number of vertices in the graph
#define V 5

// Function to find the vertex with the minimum key value, from the set of vertices not yet included in the MST
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed MST
void printMST(int parent[], int graph[V][V]) {
    cout << "Edge   Weight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "    " << graph[i][parent[i]] << "\n";
}

// Function to construct and print the MST using Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V];  // Array to store the MST
    int key[V];     // Key values to pick the minimum weight edge
    bool mstSet[V]; // To represent the set of vertices not yet included in the MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in the MST
    key[0] = 0;     // Set key value of the first vertex to 0 so that it is picked first
    parent[0] = -1; // First node is always the root of the MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in the MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update the key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
            // Update key[v] only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main() {
    // Input graph as an adjacency matrix
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // Apply Prim's algorithm to find the MST
    primMST(graph);

    return 0;
}
