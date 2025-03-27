// BST Delete Operation with Explanation
// Here is the C++ implementation of the BST delete operation, including the y != z test:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    // Helper function to find the minimum node in a subtree
    Node* findMin(Node* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete a node
    Node* deleteNode(Node* node, int key) {
        if (!node) {
            return nullptr; // Key not found
        }

        // Search for the node to delete
        if (key < node->data) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->data) {
            node->right = deleteNode(node->right, key);
        } else {
            // Node to delete found

            // Case 1: Node has no children or only one child
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 2: Node has two children
            // Find the in-order successor (smallest in the right subtree)
            Node* successor = findMin(node->right);

            // Copy the successor's data to the current node
            node->data = successor->data;

            // Delete the successor node
            node->right = deleteNode(node->right, successor->data);
        }
        return node;
    }

    // Helper function for in-order traversal
    void inOrderHelper(Node* node) const {
        if (node) {
            inOrderHelper(node->left);
            cout << node->data << " ";
            inOrderHelper(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    // Insert a new node
    void insert(int value) {
        root = insertHelper(root, value);
    }

    // Delete a node
    void remove(int key) {
        root = deleteNode(root, key);
    }

    // In-order traversal
    void inOrder() const {
        cout << "In-order traversal: ";
        inOrderHelper(root);
        cout << endl;
    }

private:
    // Helper function to insert a new node
    Node* insertHelper(Node* node, int value) {
        if (!node) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertHelper(node->left, value);
        } else if (value > node->data) {
            node->right = insertHelper(node->right, value);
        }
        return node;
    }
};

int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "BST before deletion:" << endl;
    bst.inOrder();

    bst.remove(50); // Delete node with value 50

    cout << "BST after deletion:" << endl;
    bst.inOrder();

    return 0;
}
