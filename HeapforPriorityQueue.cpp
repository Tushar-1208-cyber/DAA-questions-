#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int* heapArr;
    int capacity;
    int size;

    // Function to maintain max heap property by moving element up
    void heapifyUp(int index) {
        if (index == 0) return;  // Reached the root
        int parentIndex = (index - 1) / 2;

        if (heapArr[index] > heapArr[parentIndex]) {
            swap(heapArr[index], heapArr[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    // Function to maintain max heap property by moving element down
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
    // Constructor to initialize the priority queue with a fixed capacity
    PriorityQueue(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->heapArr = new int[capacity];
    }

    // Insert element into the priority queue
    void enqueue(int value) {
        if (size == capacity) {
            cout << "Priority Queue is full!" << endl;
            return;
        }
        heapArr[size] = value;
        heapifyUp(size);
        size++;
    }

    // Remove and return the highest priority element (the root of the max heap)
    int dequeue() {
        if (size == 0) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        int maxValue = heapArr[0];  // The root of the heap is the highest priority element
        heapArr[0] = heapArr[size - 1];
        size--;
        heapifyDown(0);  // Restore the heap property
        return maxValue;
    }

    // Peek at the highest priority element without removing it
    int peek() {
        if (size == 0) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        return heapArr[0];
    }

    // Check if the priority queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the priority queue is full
    bool isFull() {
        return size == capacity;
    }

    // Destructor to free the allocated memory
    ~PriorityQueue() {
        delete[] heapArr;
    }
};

int main() {
    int capacity = 10;
    PriorityQueue pq(capacity);

    // Enqueue elements
    pq.enqueue(30);
    pq.enqueue(20);
    pq.enqueue(50);
    pq.enqueue(10);
    pq.enqueue(40);

    // Peek at the highest priority element
    cout << "Highest priority element: " << pq.peek() << endl;

    // Dequeue elements
    cout << "Dequeue: " << pq.dequeue() << endl;
    cout << "Dequeue: " << pq.dequeue() << endl;
    cout << "Dequeue: " << pq.dequeue() << endl;

    // Peek again after dequeuing some elements
    cout << "Highest priority element after dequeues: " << pq.peek() << endl;

    // Enqueue more elements
    pq.enqueue(60);
    pq.enqueue(70);

    // Dequeue the remaining elements
    while (!pq.isEmpty()) {
        cout << "Dequeue: " << pq.dequeue() << endl;
    }

    return 0;
}
