// 1. Reverse a Linked List
// Question: Implement a function to reverse a linked list.

#include <iostream>
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

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

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

    list.append(10);
    list.append(20);
    list.append(30);

    cout << "Original List: ";
    list.print();

    list.reverse();
    cout << "Reversed List: ";
    list.print();

    return 0;
}

// 2. Detect Cycle in a Linked List
// Question: Implement a function to detect if a linked list has a cycle.

#include <iostream>
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

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    bool hasCycle() const {
        if (!head) {
            return false;
        }
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    void createCycle(int pos) {
        if (pos < 0) {
            return;
        }
        Node* current = head;
        Node* cycleNode = nullptr;
        int index = 0;

        while (current->next) {
            if (index == pos) {
                cycleNode = current;
            }
            current = current->next;
            index++;
        }
        current->next = cycleNode;
    }

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

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);

    cout << "Original List: ";
    list.print();

    list.createCycle(1); // Create a cycle at position 1
    cout << "Has Cycle: " << (list.hasCycle() ? "Yes" : "No") << endl;

    return 0;
}


// 3. Merge Two Sorted Linked Lists
// Question: Implement a function to merge two sorted linked lists into a single sorted linked list.

#include <iostream>
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

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void print() const {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    static Node* mergeSortedLists(Node* l1, Node* l2) {
        Node dummy(0);
        Node* tail = &dummy;

        while (l1 && l2) {
            if (l1->data < l2->data) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }

        return dummy.next;
    }

    void setHead(Node* newHead) {
        head = newHead;
    }
};

int main() {
    LinkedList list1, list2;

    list1.append(10);
    list1.append(20);
    list1.append(30);

    list2.append(15);
    list2.append(25);
    list2.append(35);

    cout << "List 1: ";
    list1.print();
    cout << "List 2: ";
    list2.print();

    Node* mergedHead = LinkedList::mergeSortedLists(list1.getHead(), list2.getHead());
    LinkedList mergedList;
    mergedList.setHead(mergedHead);

    cout << "Merged List: ";
    mergedList.print();

    return 0;
}


// 4. Find the Middle of a Linked List
// Question: Implement a function to find the middle node of a linked list.

#include <iostream>
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

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    Node* findMiddle() const {
        if (!head) {
            return nullptr;
        }
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

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

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    cout << "List: ";
    list.print();

    Node* middle = list.findMiddle();
    if (middle) {
        cout << "Middle Node: " << middle->data << endl;
    } else {
        cout << "List is empty." << endl;
    }

    return 0;
}
