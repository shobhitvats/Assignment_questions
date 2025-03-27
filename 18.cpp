#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

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

    // Helper function for level-order traversal
    void levelOrderHelper(Node* node) const {
        if (!node) return;
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        // Destructor to delete the tree
        deleteTree(root);
    }

    // Insert a node in the binary tree (level-order insertion)
    void insert(int value) {
        if (!root) {
            root = new Node(value);
            return;
        }
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (!current->left) {
                current->left = new Node(value);
                return;
            } else {
                q.push(current->left);
            }

            if (!current->right) {
                current->right = new Node(value);
                return;
            } else {
                q.push(current->right);
            }
        }
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

    // Level-order traversal
    void levelOrder() const {
        cout << "Level-order traversal: ";
        levelOrderHelper(root);
        cout << endl;
    }

    // Delete the tree
    void deleteTree(Node* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }
};

int main() {
    BinaryTree tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    tree.inOrder();
    tree.preOrder();
    tree.postOrder();
    tree.levelOrder();

    return 0;
}
