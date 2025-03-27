// 1. Implement a Min-Priority Queue
// Question: Implement a priority queue where the element with the smallest value has the highest priority.

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


// 2. Merge K Sorted Arrays Using a Min-Priority Queue
// Question: Implement a function to merge K sorted arrays using a min-priority queue.

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


// 3. Find the Kth Smallest Element Using a Max-Priority Queue
// Question: Implement a function to find the Kth smallest element in an array using a max-priority queue.

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


// 4. Check if an Array Represents a Max-Heap
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
