#include <iostream>
#include <algorithm>
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

// Edge structure to represent a weighted edge
struct Edge {
    int src, dest, weight;
};

// Comparator function to sort edges by weight
bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
void kruskalMST(Edge edges[], int numEdges, int numVertices) {
    // Sort the edges by weight
    sort(edges, edges + numEdges, compareEdges);

    // Create a disjoint set for the number of vertices
    DisjointSet ds(numVertices);

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    int mstWeight = 0;

    // Process each edge in sorted order
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;

        // Check if including this edge forms a cycle
        if (ds.find(u) != ds.find(v)) {
            // If not, include it in the MST
            ds.unionSets(u, v);
            cout << u << " -- " << v << " == " << weight << endl;
            mstWeight += weight;
        }
    }

    cout << "Total weight of MST: " << mstWeight << endl;
}

int main() {
    int numVertices = 4;
    int numEdges = 5;

    // Example graph with weighted edges
    Edge edges[5] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // Run Kruskal's algorithm to find the MST
    kruskalMST(edges, numEdges, numVertices);

    return 0;
}
