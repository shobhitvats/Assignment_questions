// 1. Implement a Min-Heap with Non-Recursive minHeapify
// Question: Implement a Min-Heap with a non-recursive minHeapify function.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    // Non-recursive minHeapify function
    void minHeapify(int index) {
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
    // Insert a new element into the heap
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;

        // Heapify up
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

    // Remove and return the minimum element
    int extractMin() {
        if (heap.empty()) {
            throw underflow_error("Heap is empty");
        }
        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            minHeapify(0); // Heapify down
        }
        return minValue;
    }

    // Get the minimum element without removing it
    int getMin() const {
        if (heap.empty()) {
            throw underflow_error("Heap is empty");
        }
        return heap[0];
    }

    // Check if the heap is empty
    bool isEmpty() const {
        return heap.empty();
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
    MinHeap heap;

    heap.insert(10);
    heap.insert(5);
    heap.insert(20);
    heap.insert(1);

    cout << "Heap contents: ";
    heap.print();

    cout << "Min element: " << heap.extractMin() << endl;

    cout << "Heap after extracting min: ";
    heap.print();

    return 0;
}


// 2. Heap Sort Using Non-Recursive maxHeapify
// Question: Implement Heap Sort using a non-recursive maxHeapify function.

#include <iostream>
#include <vector>
using namespace std;

// Non-recursive maxHeapify function
void maxHeapify(vector<int>& arr, int n, int index) {
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < n && arr[leftChild] > arr[largest]) {
            largest = leftChild;
        }
        if (rightChild < n && arr[rightChild] > arr[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            swap(arr[index], arr[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

// Heap sort function
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; --i) {
        maxHeapify(arr, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]); // Move current root to end
        maxHeapify(arr, i, 0); // Heapify the reduced heap
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;

    heapSort(arr);

    cout << "Sorted array: ";
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}


// 3. Find the Kth Largest Element Using a Min-Heap
// Question: Implement a function to find the Kth largest element in an array using a Min-Heap.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    return minHeap.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << "Kth largest element: " << findKthLargest(nums, k) << endl;

    return 0;
}


// 4. Check if an Array Represents a Min-Heap
// Question: Implement a function to check if an array represents a Min-Heap.

#include <iostream>
#include <vector>
using namespace std;

bool isMinHeap(const vector<int>& arr, int index = 0) {
    int n = arr.size();
    if (index >= n) {
        return true;
    }

    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < n && arr[leftChild] < arr[index]) {
        return false;
    }
    if (rightChild < n && arr[rightChild] < arr[index]) {
        return false;
    }

    return isMinHeap(arr, leftChild) && isMinHeap(arr, rightChild);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    cout << "Is the array a Min-Heap? " << (isMinHeap(arr) ? "Yes" : "No") << endl;

    return 0;
}
