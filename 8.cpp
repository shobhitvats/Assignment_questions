#include <iostream>
#include <stdexcept>
using namespace std;

class myArray {
private:
    int* arr;       // Pointer to the array
    int capacity;   // Maximum capacity of the array
    int size;       // Current number of elements in the array

    // Helper function to resize the array
    void resize(int newCapacity) {
        int* newArr = new int[newCapacity];
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    // Constructor
    myArray(int initialCapacity = 10) : capacity(initialCapacity), size(0) {
        arr = new int[capacity];
    }

    // Destructor
    ~myArray() {
        delete[] arr;
    }

    // Insert an element at a specific index
    void insert(int index, int value) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range");
        }
        if (size == capacity) {
            resize(capacity * 2); // Double the capacity if the array is full
        }
        for (int i = size; i > index; --i) {
            arr[i] = arr[i - 1]; // Shift elements to the right
        }
        arr[index] = value;
        size++;
    }

    // Remove an element at a specific index
    void remove(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1]; // Shift elements to the left
        }
        size--;
        if (size < capacity / 4 && capacity > 10) {
            resize(capacity / 2); // Halve the capacity if the array is too sparse
        }
    }

    // Get the current size of the array
    int getSize() const {
        return size;
    }

    // Get the current capacity of the array
    int getCapacity() const {
        return capacity;
    }

    // Print the array
    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    myArray arr;

    // Insert elements
    arr.insert(0, 10);
    arr.insert(1, 20);
    arr.insert(2, 30);
    arr.insert(1, 15); // Insert 15 at index 1

    cout << "Array after insertions: ";
    arr.print();
    cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << endl;

    // Remove elements
    arr.remove(1); // Remove element at index 1
    arr.remove(2); // Remove element at index 2

    cout << "Array after removals: ";
    arr.print();
    cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << endl;

    return 0;
}
