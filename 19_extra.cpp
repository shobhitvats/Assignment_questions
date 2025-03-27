// 1. Construct Binary Tree from Post-order and In-order Sequences
// Question: Implement a function to construct a binary tree from post-order and in-order sequences.

#include <iostream>
#include <vector>
#include <unordered_map>
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

    // Helper function to build the tree from post-order and in-order sequences
    Node* buildTree(const vector<int>& postorder, const vector<int>& inorder, int postStart, int postEnd, int inStart, int inEnd, unordered_map<int, int>& inMap) {
        if (postStart > postEnd || inStart > inEnd) {
            return nullptr;
        }

        // The last element in post-order is the root
        int rootValue = postorder[postEnd];
        Node* root = new Node(rootValue);

        // Find the index of the root in the in-order sequence
        int inIndex = inMap[rootValue];

        // Recursively build the left and right subtrees
        root->left = buildTree(postorder, inorder, postStart, postStart + (inIndex - inStart) - 1, inStart, inIndex - 1, inMap);
        root->right = buildTree(postorder, inorder, postStart + (inIndex - inStart), postEnd - 1, inIndex + 1, inEnd, inMap);

        return root;
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
    // Constructor that takes post-order and in-order sequences
    BinaryTree(const vector<int>& postorder, const vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }
        root = buildTree(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1, inMap);
    }

    // Destructor
    ~BinaryTree() {
        deleteTree(root);
    }

    // In-order traversal
    void inOrder() const {
        cout << "In-order traversal: ";
        inOrderHelper(root);
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
    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};

    BinaryTree tree(postorder, inorder);

    tree.inOrder();

    return 0;
}


// 2. Check if a Binary Tree is a Binary Search Tree (BST)
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


// 3. Find the Lowest Common Ancestor (LCA) in a Binary Tree
// Question: Implement a function to find the lowest common ancestor of two nodes in a binary tree.

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
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    Node* leftLCA = findLCA(root->left, n1, n2);
    Node* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA) {
        return root;
    }
    return leftLCA ? leftLCA : rightLCA;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node* lca = findLCA(root, 4, 5);
    cout << "LCA of 4 and 5: " << (lca ? lca->data : -1) << endl;

    return 0;
}


// 4. Serialize and Deserialize a Binary Tree
// Question: Implement functions to serialize and deserialize a binary tree.

#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Serialize the binary tree
string serialize(Node* root) {
    if (!root) {
        return "#";
    }
    return to_string(root->data) + "," + serialize(root->left) + "," + serialize(root->right);
}

// Deserialize the binary tree
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
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    string serialized = serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    Node* deserializedRoot = deserialize(serialized);
    cout << "Deserialized tree (in-order): ";
    // Implement in-order traversal to verify
    return 0;
}
