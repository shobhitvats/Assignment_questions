// 1. Stack Implementation
// Question: Implement a stack using an array in C++.

#include <iostream>
#include <stdexcept>
using namespace std;

class Stack {
private:
    int* arr;
    int capacity;
    int top;

public:
    Stack(int initialCapacity = 10) : capacity(initialCapacity), top(-1) {
        arr = new int[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top == capacity - 1) {
            throw overflow_error("Stack overflow");
        }
        arr[++top] = value;
    }

    int pop() {
        if (top == -1) {
            throw underflow_error("Stack underflow");
        }
        return arr[top--];
    }

    int peek() const {
        if (top == -1) {
            throw underflow_error("Stack is empty");
        }
        return arr[top];
    }

    bool isEmpty() const {
        return top == -1;
    }

    int getSize() const {
        return top + 1;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << endl;
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Stack size: " << stack.getSize() << endl;

    return 0;
}


// 2. Queue Implementation
// Question: Implement a queue using an array in C++.

#include <iostream>
#include <stdexcept>
using namespace std;

class Queue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    Queue(int initialCapacity = 10) : capacity(initialCapacity), front(0), rear(-1), size(0) {
        arr = new int[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (size == capacity) {
            throw overflow_error("Queue overflow");
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    int dequeue() {
        if (size == 0) {
            throw underflow_error("Queue underflow");
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    int peek() const {
        if (size == 0) {
            throw underflow_error("Queue is empty");
        }
        return arr[front];
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.peek() << endl;
    cout << "Dequeued element: " << queue.dequeue() << endl;
    cout << "Queue size: " << queue.getSize() << endl;

    return 0;
}


// 3. Linked List Implementation
// Question: Implement a singly linked list in C++ with insert and remove functions.

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

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int index, int value) {
        if (index < 0) {
            throw out_of_range("Index out of range");
        }
        Node* newNode = new Node(value);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                if (!current) {
                    throw out_of_range("Index out of range");
                }
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void remove(int index) {
        if (index < 0 || !head) {
            throw out_of_range("Index out of range");
        }
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                if (!current->next) {
                    throw out_of_range("Index out of range");
                }
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    void print() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.insert(1, 15);

    cout << "Linked List: ";
    list.print();

    list.remove(1);
    cout << "Linked List after removal: ";
    list.print();

    return 0;
}
