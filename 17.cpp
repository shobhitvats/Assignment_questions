// a. Matrix Class Using 1-D Array

#include <iostream>
#include <vector>
using namespace std;

class Matrix1D {
private:
    int rows, cols;
    vector<int> data;

public:
    // Constructor
    Matrix1D(int r, int c) : rows(r), cols(c), data(r * c, 0) {}

    // Access element at (i, j)
    int& operator()(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw out_of_range("Index out of range");
        }
        return data[i * cols + j];
    }

    // Const access element at (i, j)
    int operator()(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw out_of_range("Index out of range");
        }
        return data[i * cols + j];
    }

    // Print the matrix
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << (*this)(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix1D mat(3, 3);

    // Fill the matrix
    mat(0, 0) = 1;
    mat(1, 1) = 2;
    mat(2, 2) = 3;

    cout << "Matrix:" << endl;
    mat.print();

    return 0;
}


// b. Sparse Matrix Using Array/Vector of Pairs

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class SparseMatrix {
private:
    int rows, cols;
    vector<pair<pair<int, int>, int>> data; // ((row, col), value)

public:
    // Constructor
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    // Insert a non-zero element
    void insert(int i, int j, int value) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw out_of_range("Index out of range");
        }
        if (value != 0) {
            data.push_back({{i, j}, value});
        }
    }

    // Get the value at (i, j)
    int get(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw out_of_range("Index out of range");
        }
        for (const auto& entry : data) {
            if (entry.first.first == i && entry.first.second == j) {
                return entry.second;
            }
        }
        return 0; // Default value for sparse matrix
    }

    // Print the sparse matrix
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    SparseMatrix mat(3, 3);

    // Insert non-zero elements
    mat.insert(0, 0, 1);
    mat.insert(1, 1, 2);
    mat.insert(2, 2, 3);

    cout << "Sparse Matrix:" << endl;
    mat.print();

    return 0;
}
