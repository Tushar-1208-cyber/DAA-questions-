#include <iostream>
using namespace std;

class Heap {
private:
    int* heapArr;
    int capacity;
    int size;
    bool isMinHeap;

    void heapifyUp(int index) {
        if (index == 0) return; 
        int parentIndex = (index - 1) / 2;

        if (isMinHeap) {
            if (heapArr[index] < heapArr[parentIndex]) {
                swap(heapArr[index], heapArr[parentIndex]);
                heapifyUp(parentIndex);
            }
        } else { 
            if (heapArr[index] > heapArr[parentIndex]) {
                swap(heapArr[index], heapArr[parentIndex]);
                heapifyUp(parentIndex);
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int target = index;

        if (isMinHeap) {
            if (leftChild < size && heapArr[leftChild] < heapArr[target])
                target = leftChild;
            if (rightChild < size && heapArr[rightChild] < heapArr[target])
                target = rightChild;
        } else {
            if (leftChild < size && heapArr[leftChild] > heapArr[target])
                target = leftChild;
            if (rightChild < size && heapArr[rightChild] > heapArr[target])
                target = rightChild;
        }

        if (target != index) {
            swap(heapArr[index], heapArr[target]);
            heapifyDown(target);
        }
    }

public:
    Heap(int capacity, bool isMinHeap) {
        this->capacity = capacity;
        this->size = 0;
        this->heapArr = new int[capacity];
        this->isMinHeap = isMinHeap;
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }
        heapArr[size] = value;
        heapifyUp(size);
        size++;
    }

    int extractRoot() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int rootValue = heapArr[0];
        heapArr[0] = heapArr[size - 1];
        size--;
        heapifyDown(0);
        return rootValue;
    }

    int getRoot() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return heapArr[0];
    }

    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << heapArr[i] << " ";
        cout << endl;
    }

    ~Heap() {
        delete[] heapArr;
    }
};

int main() {
    int capacity = 10;
    
    Heap maxHeap(capacity, false); 
    maxHeap.insert(10);
    maxHeap.insert(30);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(1);

    cout << "Max Heap: ";
    maxHeap.printHeap();
    cout << "Extracted max: " << maxHeap.extractRoot() << endl;
    cout << "Max Heap after extraction: ";
    maxHeap.printHeap();

    Heap minHeap(capacity, true); 
    minHeap.insert(10);
    minHeap.insert(30);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(1);

    cout << "\nMin Heap: ";
    minHeap.printHeap();
    cout << "Extracted min: " << minHeap.extractRoot() << endl;
    cout << "Min Heap after extraction: ";
    minHeap.printHeap();

    return 0;
}