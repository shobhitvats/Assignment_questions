// 1. Matrix Multiplication
// Question: Implement a class for matrices and provide a function to multiply two matrices.

#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    vector<vector<int>> data;
    int rows, cols;

public:
    Matrix(int r, int c, const vector<vector<int>>& values) : rows(r), cols(c), data(values) {
        if (values.size() != r || (r > 0 && values[0].size() != c)) {
            throw invalid_argument("Invalid matrix dimensions");
        }
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Matrix dimensions do not match for multiplication");
        }
        vector<vector<int>> result(rows, vector<int>(other.cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return Matrix(rows, other.cols, result);
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix m1(2, 3, {{1, 2, 3}, {4, 5, 6}});
    Matrix m2(3, 2, {{7, 8}, {9, 10}, {11, 12}});

    cout << "Matrix 1:" << endl;
    m1.print();
    cout << "Matrix 2:" << endl;
    m2.print();

    Matrix product = m1 * m2;
    cout << "Product:" << endl;
    product.print();

    return 0;
}


// 2. Binary Search Tree (BST)
// Question: Implement a Binary Search Tree (BST) with insert, search, and in-order traversal functions.

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

    Node* insert(Node* node, int value) {
        if (!node) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool search(Node* node, int value) const {
        if (!node) {
            return false;
        }
        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    void inOrder(Node* node) const {
        if (node) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) const {
        return search(root, value);
    }

    void inOrder() const {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);

    cout << "In-order traversal: ";
    bst.inOrder();

    cout << "Search for 7: " << (bst.search(7) ? "Found" : "Not Found") << endl;
    cout << "Search for 12: " << (bst.search(12) ? "Found" : "Not Found") << endl;

    return 0;
}


// 3. Graph Representation and DFS
// Question: Implement a graph using an adjacency list and provide a Depth-First Search (DFS) function.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;

    void dfsUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }

public:
    Graph(int V) : vertices(V), adjList(V) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    void dfs(int start) {
        vector<bool> visited(vertices, false);
        dfsUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "DFS starting from vertex 0: ";
    g.dfs(0);

    return 0;
}
