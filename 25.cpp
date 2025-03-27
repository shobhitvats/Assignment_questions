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

    // Helper function to insert a node
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

    // Helper function to search for a node
    bool searchHelper(Node* node, int value) const {
        if (!node) {
            return false;
        }
        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return searchHelper(node->left, value);
        } else {
            return searchHelper(node->right, value);
        }
    }

    // Helper function to find the minimum node in a subtree
    Node* findMin(Node* node) const {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete a node
    Node* deleteHelper(Node* node, int value) {
        if (!node) {
            return nullptr;
        }
        if (value < node->data) {
            node->left = deleteHelper(node->left, value);
        } else if (value > node->data) {
            node->right = deleteHelper(node->right, value);
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
            node->right = deleteHelper(node->right, successor->data);
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

    // Helper function for pre-order traversal
    void preOrderHelper(Node* node) const {
        if (node) {
            cout << node->data << " ";
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }

    // Helper function for post-order traversal
    void postOrderHelper(Node* node) const {
        if (node) {
            postOrderHelper(node->left);
            postOrderHelper(node->right);
            cout << node->data << " ";
        }
    }

public:
    BST() : root(nullptr) {}

    // Insert a new node
    void insert(int value) {
        root = insertHelper(root, value);
    }

    // Search for a node
    bool search(int value) const {
        return searchHelper(root, value);
    }

    // Delete a node
    void remove(int value) {
        root = deleteHelper(root, value);
    }

    // In-order traversal
    void inOrder() const {
        cout << "In-order traversal: ";
        inOrderHelper(root);
        cout << endl;
    }

    // Pre-order traversal
    void preOrder() const {
        cout << "Pre-order traversal: ";
        preOrderHelper(root);
        cout << endl;
    }

    // Post-order traversal
    void postOrder() const {
        cout << "Post-order traversal: ";
        postOrderHelper(root);
        cout << endl;
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

    cout << "BST traversals:" << endl;
    bst.inOrder();
    bst.preOrder();
    bst.postOrder();

    cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search for 100: " << (bst.search(100) ? "Found" : "Not Found") << endl;

    bst.remove(50);
    cout << "BST after deleting 50:" << endl;
    bst.inOrder();

    return 0;
}
