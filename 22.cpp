#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    // Non-recursive heapify function for max-heap
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
    // Insert an element into the priority queue
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Remove and return the element with the highest priority
    int pop() {
        if (heap.empty()) {
            throw underflow_error("Priority queue is empty");
        }
        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return maxValue;
    }

    // Get the element with the highest priority without removing it
    int top() const {
        if (heap.empty()) {
            throw underflow_error("Priority queue is empty");
        }
        return heap[0];
    }

    // Check if the priority queue is empty
    bool isEmpty() const {
        return heap.empty();
    }

    // Print the priority queue
    void print() const {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

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
