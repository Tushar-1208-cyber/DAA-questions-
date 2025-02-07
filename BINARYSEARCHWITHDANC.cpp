#include<iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target)
{
    if (left > right)
        return -1;    
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
        return mid;
    if (target < arr[mid])
        return binarySearch(arr, left, mid - 1, target);
    return binarySearch(arr, mid + 1, right, target);
}
void printResult(int result, int target) 
{
    if (result != -1)
        cout << "Element " << target << " is present at index " << result << "." << endl;
    else
        cout << "Element " << target << " is not present in the array." << endl;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};  // Sorted array
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int target = 10;  

    int result = binarySearch(arr, 0, arrSize - 1, target);
    printResult(result, target);
    return 0;
}
