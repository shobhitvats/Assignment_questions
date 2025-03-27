// 1. Height of a Binary Tree
// Question: Implement a function to calculate the height of a binary tree.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int height(Node* node) {
    if (!node) {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Height of the tree: " << height(root) << endl;

    return 0;
}


// 2. Check if a Binary Tree is Balanced
// Question: Implement a function to check if a binary tree is balanced.

#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int height(Node* node) {
    if (!node) {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node* node) {
    if (!node) {
        return true;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Is the tree balanced? " << (isBalanced(root) ? "Yes" : "No") << endl;

    return 0;
}


// 3. Count the Number of Nodes in a Binary Tree
// Question: Implement a function to count the number of nodes in a binary tree.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int countNodes(Node* node) {
    if (!node) {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Number of nodes in the tree: " << countNodes(root) << endl;

    return 0;
}


// 4. Check if Two Trees are Identical
// Question: Implement a function to check if two binary trees are identical.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool areIdentical(Node* root1, Node* root2) {
    if (!root1 && !root2) {
        return true;
    }
    if (!root1 || !root2) {
        return false;
    }
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    cout << "Are the trees identical? " << (areIdentical(root1, root2) ? "Yes" : "No") << endl;

    return 0;
}
