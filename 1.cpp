#include <iostream>
using namespace std;

// Disjoint Set Data Structure
class DisjointSet {
private:
    int *parent, *rank;
    int n;

public:
    // Constructor to initialize the data structures
    DisjointSet(int n) {
        this->n = n;
        parent = new int[n];
        rank = new int[n];

        // Initialize each node to be its own parent and rank to 0
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find function with path compression
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    // Union function with union by rank
    void unionSets(int u, int v) {
        int uRoot = find(u);
        int vRoot = find(v);

        // If both have the same root, they are already in the same set
        if (uRoot == vRoot) {
            return;
        }

        // Union by rank
        if (rank[uRoot] < rank[vRoot]) {
            parent[uRoot] = vRoot;
        } else if (rank[uRoot] > rank[vRoot]) {
            parent[vRoot] = uRoot;
        } else {
            parent[vRoot] = uRoot;
            rank[uRoot]++;
        }
    }

    // Destructor to free allocated memory
    ~DisjointSet() {
        delete[] parent;
        delete[] rank;
    }
};

// Function to detect a cycle in an undirected graph
bool detectCycle(int edges[][2], int numEdges, int numVertices) {
    DisjointSet ds(numVertices);

    // Process each edge
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // If u and v belong to the same set, a cycle is detected
        if (ds.find(u) == ds.find(v)) {
            return true;
        }

        // Otherwise, union the sets
        ds.unionSets(u, v);
    }

    // No cycle detected
    return false;
}

int main() {
    int numVertices = 4;
    int numEdges = 3;

    // Example graph edges
    int edges[3][2] = {
        {0, 1},
        {1, 2},
        {2, 3}
    };

    if (detectCycle(edges, numEdges, numVertices)) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }

    return 0;
}
