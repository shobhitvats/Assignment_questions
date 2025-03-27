// 1. Implement a Stack Using Queues
// Question: Implement a stack using two queues.

#include <iostream>
#include <queue>
#include <stdexcept>
using namespace std;

class StackUsingQueues {
private:
    queue<int> q1;
    queue<int> q2;

public:
    // Push operation (costly)
    void push(int value) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Push the new element into q1
        q1.push(value);
        // Move all elements back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Pop operation (efficient)
    int pop() {
        if (isEmpty()) {
            throw underflow_error("Stack underflow");
        }
        int value = q1.front();
        q1.pop();
        return value;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return q1.empty();
    }

    // Get the top element of the stack
    int top() const {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return q1.front();
    }

    // Print the stack
    void print() const {
        queue<int> temp = q1;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingQueues stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack contents: ";
    stack.print();

    cout << "Top element: " << stack.top() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    cout << "Stack after pop: ";
    stack.print();

    return 0;
}


// 2. Implement a Min Stack
// Question: Implement a stack that supports push, pop, top, and retrieving the minimum element in constant time.

#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    // Push operation
    void push(int value) {
        mainStack.push(value);
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
    }

    // Pop operation
    int pop() {
        if (isEmpty()) {
            throw underflow_error("Stack underflow");
        }
        int value = mainStack.top();
        mainStack.pop();
        if (value == minStack.top()) {
            minStack.pop();
        }
        return value;
    }

    // Get the top element
    int top() const {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return mainStack.top();
    }

    // Get the minimum element
    int getMin() const {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return minStack.top();
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return mainStack.empty();
    }

    // Print the stack
    void print() const {
        stack<int> temp = mainStack;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    MinStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(5);
    stack.push(15);

    cout << "Stack contents: ";
    stack.print();

    cout << "Top element: " << stack.top() << endl;
    cout << "Minimum element: " << stack.getMin() << endl;

    cout << "Popped element: " << stack.pop() << endl;

    cout << "Stack after pop: ";
    stack.print();

    return 0;
}


// 3. Implement a Queue Using a Single Stack
// Question: Implement a queue using a single stack.

#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

class QueueUsingSingleStack {
private:
    stack<int> s;

    // Helper function to insert at the bottom of the stack
    void insertAtBottom(int value) {
        if (s.empty()) {
            s.push(value);
        } else {
            int temp = s.top();
            s.pop();
            insertAtBottom(value);
            s.push(temp);
        }
    }

public:
    // Enqueue operation (costly)
    void enqueue(int value) {
        insertAtBottom(value);
    }

    // Dequeue operation (efficient)
    int dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue underflow");
        }
        int value = s.top();
        s.pop();
        return value;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return s.empty();
    }

    // Get the front element of the queue
    int peek() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        return s.top();
    }

    // Print the queue
    void print() const {
        stack<int> temp = s;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    QueueUsingSingleStack q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue contents: ";
    q.print();

    cout << "Front element: " << q.peek() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;

    cout << "Queue after dequeue: ";
    q.print();

    return 0;
}
