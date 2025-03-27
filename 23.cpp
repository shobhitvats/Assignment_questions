#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> heap;

    // Non-recursive heapify function for max-heap
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
    // Constructor to build a heap from an array
    Heap(const vector<int>& arr) : heap(arr) {
        // Build the heap
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            heapifyDown(i, heap.size());
        }
    }

    // Perform heap sort
    void heapSort() {
        for (int i = heap.size() - 1; i > 0; --i) {
            swap(heap[0], heap[i]); // Move the root (max element) to the end
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

    Heap heap(arr);

    cout << "Original array: ";
    heap.print();

    heap.heapSort();

    cout << "Sorted array: ";
    heap.print();

    return 0;
}
