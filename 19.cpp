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

    // Helper function to build the tree from pre-order and in-order sequences
    Node* buildTree(const vector<int>& preorder, const vector<int>& inorder, int preStart, int inStart, int inEnd, unordered_map<int, int>& inMap) {
        if (preStart >= preorder.size() || inStart > inEnd) {
            return nullptr;
        }

        // The first element in pre-order is the root
        int rootValue = preorder[preStart];
        Node* root = new Node(rootValue);

        // Find the index of the root in the in-order sequence
        int inIndex = inMap[rootValue];

        // Recursively build the left and right subtrees
        root->left = buildTree(preorder, inorder, preStart + 1, inStart, inIndex - 1, inMap);
        root->right = buildTree(preorder, inorder, preStart + (inIndex - inStart) + 1, inIndex + 1, inEnd, inMap);

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
    // Constructor that takes pre-order and in-order sequences
    BinaryTree(const vector<int>& preorder, const vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }
        root = buildTree(preorder, inorder, 0, 0, inorder.size() - 1, inMap);
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
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    BinaryTree tree(preorder, inorder);

    tree.inOrder();

    return 0;
}
