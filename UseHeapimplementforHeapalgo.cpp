#include <iostream>
using namespace std;

class Heap {
private:
    int* heapArr;
    int capacity;
    int size;

    // Heapify function to maintain max heap property (downward)
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heapArr[leftChild] > heapArr[largest])
            largest = leftChild;

        if (rightChild < size && heapArr[rightChild] > heapArr[largest])
            largest = rightChild;

        if (largest != index) {
            swap(heapArr[index], heapArr[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Constructor
    Heap(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->heapArr = new int[capacity];
    }

    // Insert element into the heap (build phase for heap sort)
    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }
        heapArr[size] = value;
        size++;
    }

    // Build the heap (Max Heap for ascending sort)
    void buildMaxHeap() {
        for (int i = (size / 2) - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    // Heap Sort implementation
    void heapSort() {
        // Step 1: Build the Max Heap
        buildMaxHeap();

        // Step 2: Extract elements from the heap and place them in sorted order
        for (int i = size - 1; i > 0; i--) {
            // Move the current root (maximum element) to the end of the array
            swap(heapArr[0], heapArr[i]);
            size--;  // Reduce the size of the heap
            heapifyDown(0);  // Call heapify to restore the heap property
        }
    }

    // Print the array (sorted or unsorted)
    void printArray() {
        for (int i = 0; i < capacity; i++) {
            cout << heapArr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~Heap() {
        delete[] heapArr;
    }
};

int main() {
    int capacity = 10;
    int arr[] = {10, 30, 20, 5, 60, 25, 50, 45, 15, 40};
    
    // Create a heap with given capacity
    Heap heap(capacity);

    // Insert elements into the heap
    for (int i = 0; i < capacity; i++) {
        heap.insert(arr[i]);
    }

    cout << "Original array: ";
    heap.printArray();

    // Perform Heap Sort
    heap.heapSort();

    cout << "Sorted array (ascending): ";
    heap.printArray();

    return 0;
}
