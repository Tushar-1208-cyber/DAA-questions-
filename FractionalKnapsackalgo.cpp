#include <iostream>
#include <algorithm>

using namespace std;

// Structure to represent an item with a value and weight
struct Item {
    int value, weight;

    // Constructor for convenience
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparison function to sort items by value/weight ratio in descending order
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int W, Item arr[], int n) {
    // Sort items by value/weight ratio
    sort(arr, arr + n, cmp);

    double totalValue = 0.0;  // Variable to store the maximum value

    // Traverse sorted items and pick them while possible
    for (int i = 0; i < n; i++) {
        // If the whole item can be added, take it
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        }
        // If only a fraction of the item can be added, take the fraction
        else {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;  // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int W = 50;  // Maximum weight capacity of the knapsack

    // Array of items with their values and weights
    Item arr[] = { {60, 10}, {100, 20}, {120, 30} };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Calculate and print the maximum value we can obtain
    double maxValue = fractionalKnapsack(W, arr, n);

    cout << "Maximum value we can obtain = " << maxValue << endl;

    return 0;
}
