#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Non-recursive maxHeapify function
    void maxHeapify(int index) {
        int n = heap.size();
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < n && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }
            if (rightChild < n && heap[rightChild] > heap[largest]) {
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
    // Insert a new element into the heap
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;

        // Heapify up
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

    // Remove and return the maximum element
    int extractMax() {
        if (heap.empty()) {
            throw underflow_error("Heap is empty");
        }
        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            maxHeapify(0); // Heapify down
        }
        return maxValue;
    }

    // Get the maximum element without removing it
    int getMax() const {
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
