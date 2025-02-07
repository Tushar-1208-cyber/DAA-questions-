#include<iostream>
using namespace std;

void findMinMax(int arr[], int low, int high, int &min, int &max) {
    if (low == high) 
    {
        min = max = arr[low];
        return;
    }
    if (high == low + 1) 
    {
        if (arr[low] < arr[high]) 
        {
            min = arr[low];
            max = arr[high];
        } 
        else
        {
            min = arr[high];
            max = arr[low];
        }
        return;
    }
    int mid = low + (high - low) / 2;
    int minLeft, maxLeft;
    int minRight, maxRight;
    findMinMax(arr, low, mid, minLeft, maxLeft);
    findMinMax(arr, mid + 1, high, minRight, maxRight);
    min = (minLeft < minRight) ? minLeft : minRight;
    max = (maxLeft > maxRight) ? maxLeft : maxRight;
}
int main() {
    int arr[] = {13, 4, 6, 8, 20, -5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int minElement, maxElement;
    findMinMax(arr, 0, n - 1, minElement, maxElement);
    cout << "Minimum element: " << minElement << endl;
    cout << "Maximum element: " << maxElement << endl;

    return 0;
}
