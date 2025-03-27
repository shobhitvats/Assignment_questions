// a. Stack ADT using Array/Vector

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Stack {
private:
    vector<int> data;

public:
    // Push an element onto the stack
    void push(int value) {
        data.push_back(value);
    }

    // Pop the top element from the stack
    int pop() {
        if (isEmpty()) {
            throw underflow_error("Stack underflow");
        }
        int value = data.back();
        data.pop_back();
        return value;
    }

    // Get the top element of the stack
    int peek() const {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return data.back();
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return data.empty();
    }

    // Get the size of the stack
    int size() const {
        return data.size();
    }

    // Print the stack
    void print() const {
        for (int i = data.size() - 1; i >= 0; --i) {
            cout << data[i] << endl;
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack contents:" << endl;
    stack.print();

    cout << "Top element: " << stack.peek() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    cout << "Stack after pop:" << endl;
    stack.print();

    return 0;
}


// b. Stack ADT using LinkedList

#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Pop the top element from the stack
    int pop() {
        if (isEmpty()) {
            throw underflow_error("Stack underflow");
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // Get the top element of the stack
    int peek() const {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Print the stack
    void print() const {
        Node* current = top;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack contents:" << endl;
    stack.print();

    cout << "Top element: " << stack.peek() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    cout << "Stack after pop:" << endl;
    stack.print();

    return 0;
}


// c. Queue ADT using LinkedList

#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Add an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue underflow");
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        delete temp;
        return value;
    }

    // Get the front element of the queue
    int peek() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Print the queue
    void print() const {
        Node* current = front;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Queue contents: ";
    queue.print();

    cout << "Front element: " << queue.peek() << endl;
    cout << "Dequeued element: " << queue.dequeue() << endl;

    cout << "Queue after dequeue: ";
    queue.print();

    return 0;
}
