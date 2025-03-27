// 1. Min-Heap Implementation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    // Helper function to maintain the heap property
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

    // Helper function to maintain the heap property
    void heapifyDown(int index) {
        int leftChild, rightChild, smallest;
        while (true) {
            leftChild = 2 * index + 1;
            rightChild = 2 * index + 2;
            smallest = index;

            if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
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
        heapifyUp(heap.size() - 1);
    }

    // Remove and return the minimum element
    int extractMin() {
        if (heap.empty()) {
            throw underflow_error("Heap is empty");
        }
        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
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


// 2. Heap Sort

#include <iostream>
#include <vector>
using namespace std;

// Heapify a subtree rooted at index i
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Heap sort function
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0);   // Heapify the reduced heap
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


// 3. Kth Largest Element in an Array Using Min-Heap

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


// 4. Merge K Sorted Arrays Using Min-Heap

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

    // Push the first element of each array into the heap
    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], {i, 0}});
        }
    }

    vector<int> result;

    while (!minHeap.empty()) {
        auto top = minHeap.top();
        minHeap.pop();

        int value = top.first;
        int arrayIndex = top.second.first;
        int elementIndex = top.second.second;

        result.push_back(value);

        // Push the next element from the same array
        if (elementIndex + 1 < arrays[arrayIndex].size()) {
            minHeap.push({arrays[arrayIndex][elementIndex + 1], {arrayIndex, elementIndex + 1}});
        }
    }

    return result;
}

int main() {
    vector<vector<int>> arrays = {
        {1, 3, 5},
        {2, 4, 6},
        {0, 7, 8}
    };

    vector<int> result = mergeKSortedArrays(arrays);

    cout << "Merged array: ";
    for (int value : result) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}

// Extra 

// 1. Implement a Max-Heap
// Question: Implement a Max-Heap in C++.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild, rightChild, largest;
        while (true) {
            leftChild = 2 * index + 1;
            rightChild = 2 * index + 2;
            largest = index;

            if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }
            if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
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
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            throw underflow_error("Heap is empty");
        }
        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxValue;
    }

    int getMax() const {
        if (heap.empty()) {
            throw underflow_error("Heap is empty");
        }
        return heap[0];
    }

    void print() const {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap;

    heap.insert(10);
    heap.insert(5);
    heap.insert(20);
    heap.insert(1);

    cout << "Heap contents: ";
    heap.print();

    cout << "Max element: " << heap.extractMax() << endl;

    cout << "Heap after extracting max: ";
    heap.print();

    return 0;
}


// 2. Find the Kth Smallest Element Using Max-Heap
// Question: Implement a function to find the Kth smallest element in an array using a Max-Heap.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthSmallest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;

    for (int num : nums) {
        maxHeap.push(num);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    return maxHeap.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 3;

    cout << "Kth smallest element: " << findKthSmallest(nums, k) << endl;

    return 0;
}


// 3. Check if an Array Represents a Max-Heap
// Question: Implement a function to check if an array represents a Max-Heap.

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
