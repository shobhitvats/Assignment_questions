// Yes, it is possible to implement a Queue using Stacks. There are two common approaches:

// Using Two Stacks (Costly Enqueue):

// Enqueue operation is costly, but dequeue is efficient.

// Using Two Stacks (Costly Dequeue):

// Dequeue operation is costly, but enqueue is efficient.

// Below, I will provide the implementation for the Costly Dequeue approach, as it is more intuitive and commonly used. Additionally, I will provide more C++ code-related questions and solutions that could be asked in a Data Structures and Algorithms quiz.

// Queue Implementation Using Two Stacks (Costly Dequeue)

#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1; // Main stack for enqueue
    stack<int> s2; // Temporary stack for dequeue

public:
    // Enqueue operation (efficient)
    void enqueue(int value) {
        s1.push(value);
    }

    // Dequeue operation (costly)
    int dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue underflow");
        }
        // If s2 is empty, move all elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int value = s2.top();
        s2.pop();
        return value;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return s1.empty() && s2.empty();
    }

    // Get the front element of the queue
    int peek() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        // If s2 is empty, move all elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    // Print the queue
    void print() {
        stack<int> temp = s2;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        stack<int> temp2 = s1;
        while (!temp2.empty()) {
            temp.push(temp2.top());
            temp2.pop();
        }
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    QueueUsingStacks q;

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
