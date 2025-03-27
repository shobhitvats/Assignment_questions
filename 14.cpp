#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert an element at a specific index
    void insert(int index, int value) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range");
        }
        Node* newNode = new Node(value);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

    // Remove an element at a specific index
    void remove(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        size--;
    }

    // Get the element at a specific index
    int get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Set the element at a specific index
    void set(int index, int value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->data = value;
    }

    // Get the size of the list
    int getSize() const {
        return size;
    }

    // Check if the list is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Print the linked list
    void print() const {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList list;

    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);

    cout << "List after insertions: ";
    list.print();

    list.set(1, 25);
    cout << "List after setting index 1 to 25: ";
    list.print();

    cout << "Element at index 1: " << list.get(1) << endl;

    list.remove(1);
    cout << "List after removing index 1: ";
    list.print();

    cout << "Size of the list: " << list.getSize() << endl;
    cout << "Is the list empty? " << (list.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
