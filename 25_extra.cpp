// 1. Find the Height of a BST
// Question: Implement a function to find the height of a BST.

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
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    cout << "Height of the BST: " << height(root) << endl;

    return 0;
}


// 2. Check if a Binary Tree is a BST
// Question: Implement a function to check if a binary tree is a valid BST.

#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool isBSTHelper(Node* node, int min, int max) {
    if (!node) {
        return true;
    }
    if (node->data <= min || node->data >= max) {
        return false;
    }
    return isBSTHelper(node->left, min, node->data) && isBSTHelper(node->right, node->data, max);
}

bool isBST(Node* root) {
    return isBSTHelper(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    cout << "Is the tree a BST? " << (isBST(root) ? "Yes" : "No") << endl;

    return 0;
}


// 3. Find the Lowest Common Ancestor (LCA) in a BST
// Question: Implement a function to find the lowest common ancestor of two nodes in a BST.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* findLCA(Node* root, int n1, int n2) {
    if (!root) {
        return nullptr;
    }
    if (root->data > n1 && root->data > n2) {
        return findLCA(root->left, n1, n2);
    }
    if (root->data < n1 && root->data < n2) {
        return findLCA(root->right, n1, n2);
    }
    return root;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    Node* lca = findLCA(root, 5, 15);
    cout << "LCA of 5 and 15: " << (lca ? lca->data : -1) << endl;

    return 0;
}


// 4. Serialize and Deserialize a BST
// Question: Implement functions to serialize and deserialize a BST.

#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Serialize the BST
string serialize(Node* root) {
    if (!root) {
        return "#";
    }
    return to_string(root->data) + "," + serialize(root->left) + "," + serialize(root->right);
}

// Deserialize the BST
Node* deserializeHelper(istringstream& iss) {
    string token;
    getline(iss, token, ',');
    if (token == "#") {
        return nullptr;
    }
    Node* root = new Node(stoi(token));
    root->left = deserializeHelper(iss);
    root->right = deserializeHelper(iss);
    return root;
}

Node* deserialize(string data) {
    istringstream iss(data);
    return deserializeHelper(iss);
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    string serialized = serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    Node* deserializedRoot = deserialize(serialized);
    cout << "Deserialized tree (in-order): ";
    // Implement in-order traversal to verify
    return 0;
}
