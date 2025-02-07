#include<iostream>
using namespace std;

void findMinMax(int arr[], int n, int &min, int &max) {
    min = arr[0];
    max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
    min = arr[i];  
        if (arr[i] > max)
            max = arr[i]; 
    }
}
int main() {
    int arr[] = {12, 3, 5, 7, 19, -4, 0}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int minElement, maxElement;
    findMinMax(arr, n, minElement, maxElement);
    cout<< "Minimum element: " << minElement << endl;
    cout<< "Maximum element: " << maxElement << endl;

    return 0;
}
