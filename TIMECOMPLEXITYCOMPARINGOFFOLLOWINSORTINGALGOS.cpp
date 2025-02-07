#include <iostream>
#include <ctime>  // For time functions

using namespace std;

// Function to generate a random array
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Bubble Sort
int bubbleSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return comparisons;
}

// Selection Sort
int selectionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    return comparisons;
}

// Insertion Sort
int insertionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        comparisons++; // For the comparison when arr[j] <= key
        arr[j + 1] = key;
    }
    return comparisons;
}

// Merge Sort - Helper function to merge two subarrays
int merge(int arr[], int left, int mid, int right) {
    int comparisons = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;

    return comparisons;
}

// Merge Sort - Main function
int mergeSort(int arr[], int left, int right) {
    int comparisons = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        comparisons += mergeSort(arr, left, mid);
        comparisons += mergeSort(arr, mid + 1, right);

        comparisons += merge(arr, left, mid, right);
    }
    return comparisons;
}

// Quick Sort - Partition function
int partition(int arr[], int low, int high, int& comparisons) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Quick Sort - Main function
int quickSort(int arr[], int low, int high) {
    int comparisons = 0;
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);

        comparisons += quickSort(arr, low, pi - 1);
        comparisons += quickSort(arr, pi + 1, high);
    }
    return comparisons;
}

// Heap Sort - Heapify function
void heapify(int arr[], int n, int i, int& comparisons) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    comparisons++;
    if (left < n && arr[left] > arr[largest])
        largest = left;

    comparisons++;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest, comparisons);
    }
}

// Heap Sort - Main function
int heapSort(int arr[], int n) {
    int comparisons = 0;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, comparisons);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0, comparisons);
    }

    return comparisons;
}

int main() {
    const int n = 20;
    const int trials = 10;
    int results[trials][6];

    srand(time(0));  // Seed for random number generation

    for (int t = 0; t < trials; ++t) {
        int arr[n];
        generateRandomArray(arr, n);

        int arrCopy[n];

        // Bubble Sort
        for (int i = 0; i < n; ++i) arrCopy[i] = arr[i];
        results[t][0] = bubbleSort(arrCopy, n);

        // Selection Sort
        for (int i = 0; i < n; ++i) arrCopy[i] = arr[i];
        results[t][1] = selectionSort(arrCopy, n);

        // Insertion Sort
        for (int i = 0; i < n; ++i) arrCopy[i] = arr[i];
        results[t][2] = insertionSort(arrCopy, n);

        // Merge Sort
        for (int i = 0; i < n; ++i) arrCopy[i] = arr[i];
        results[t][3] = mergeSort(arrCopy, 0, n - 1);

        // Quick Sort
        for (int i = 0; i < n; ++i) arrCopy[i] = arr[i];
        results[t][4] = quickSort(arrCopy, 0, n - 1);

        // Heap Sort
        for (int i = 0; i < n; ++i) arrCopy[i] = arr[i];
        results[t][5] = heapSort(arrCopy, n);
    }

    // Display the results
    cout << "Trial\tBubble Sort\tSelection Sort\tInsertion Sort\tMerge Sort\tQuick Sort\tHeap Sort\n";
    for (int t = 0; t < trials; ++t) {
        cout << t + 1 << "\t";
        for (int j = 0; j < 6; ++j) {
            cout << results[t][j] << "\t\t";
        }
        cout << endl;
    }

    return 0;
}
