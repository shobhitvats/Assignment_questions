// 1. Implement Heap Sort Using a Min-Heap
// Question: Implement Heap Sort using a min-heap.

#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    // Non-recursive heapify function for min-heap
    void heapifyDown(int index, int heapSize) {
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < heapSize && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < heapSize && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }
            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    // Constructor to build a heap from an array
    MinHeap(const vector<int>& arr) : heap(arr) {
        // Build the heap
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            heapifyDown(i, heap.size());
        }
    }

    // Perform heap sort
    void heapSort() {
        for (int i = heap.size() - 1; i > 0; --i) {
            swap(heap[0], heap[i]); // Move the root (min element) to the end
            heapifyDown(0, i);      // Heapify the reduced heap
        }
    }

    // Print the heap
    void print() const {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    MinHeap heap(arr);

    cout << "Original array: ";
    heap.print();

    heap.heapSort();

    cout << "Sorted array: ";
    heap.print();

    return 0;
}


// 2. Find the Kth Largest Element Using Heap Sort
// Question: Implement a function to find the Kth largest element in an array using Heap Sort.

#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> heap;

    void heapifyDown(int index, int heapSize) {
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < heapSize && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }
            if (rightChild < heapSize && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }
            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    Heap(const vector<int>& arr) : heap(arr) {
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            heapifyDown(i, heap.size());
        }
    }

    int extractMax() {
        if (heap.empty()) {
            throw underflow_error("Heap is empty");
        }
        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0, heap.size());
        }
        return maxValue;
    }

    int findKthLargest(int k) {
        for (int i = 0; i < k - 1; ++i) {
            extractMax();
        }
        return extractMax();
    }
};

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 2;

    Heap heap(arr);

    cout << "Kth largest element: " << heap.findKthLargest(k) << endl;

    return 0;
}


// 3. Check if an Array Represents a Max-Heap
// Question: Implement a function to check if an array represents a max-heap.

#include <iostream>
#include <vector>
using namespace std;

bool isMaxHeap(const vector<int>& arr, int index = 0) {
    int n = arr.size();
    if (index >= n) {
        return true;
    }

    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < n && arr[leftChild] > arr[index]) {
        return false;
    }
    if (rightChild < n && arr[rightChild] > arr[index]) {
        return false;
    }

    return isMaxHeap(arr, leftChild) && isMaxHeap(arr, rightChild);
}

int main() {
    vector<int> arr = {10, 5, 3, 2, 4, 1};

    cout << "Is the array a Max-Heap? " << (isMaxHeap(arr) ? "Yes" : "No") << endl;

    return 0;
}


// 4. Implement a Priority Queue Using a Min-Heap
// Question: Implement a priority queue using a min-heap.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinPriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < n && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < n && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }
            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int pop() {
        if (heap.empty()) {
            throw underflow_error("Priority queue is empty");
        }
        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return minValue;
    }

    int top() const {
        if (heap.empty()) {
            throw underflow_error("Priority queue is empty");
        }
        return heap[0];
    }

    bool isEmpty() const {
        return heap.empty();
    }

    void print() const {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main() {
    MinPriorityQueue pq;

    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(1);

    cout << "Priority queue contents: ";
    pq.print();

    cout << "Top element: " << pq.top() << endl;
    cout << "Popped element: " << pq.pop() << endl;

    cout << "Priority queue after pop: ";
    pq.print();

    return 0;
}
