// 1. Reverse a Queue
// Question: Implement a function to reverse a queue using a stack.

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int>& q) {
    stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Original Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    q.push(10);
    q.push(20);
    q.push(30);

    reverseQueue(q);

    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}


// 2. Check Balanced Parentheses
// Question: Implement a function to check if a string of parentheses is balanced using a stack.

#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(const string& str) {
    stack<char> s;
    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    string str = "{[()]}";
    cout << "Is balanced? " << (isBalanced(str) ? "Yes" : "No") << endl;

    return 0;
}



// 3. Implement a Circular Queue
// Question: Implement a circular queue using an array.

#include <iostream>
#include <stdexcept>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front, rear, capacity;

public:
    CircularQueue(int size) : capacity(size), front(-1), rear(-1) {
        arr = new int[capacity];
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() const {
        return front == -1;
    }

    bool isFull() const {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            throw overflow_error("Queue overflow");
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue underflow");
        }
        int value = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return value;
    }

    int peek() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        return arr[front];
    }

    void print() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue contents: ";
    q.print();

    cout << "Dequeued element: " << q.dequeue() << endl;

    cout << "Queue after dequeue: ";
    q.print();

    return 0;
}
