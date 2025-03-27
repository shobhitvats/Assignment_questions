// 1. Matrix Multiplication
// Question: Implement matrix multiplication for the Matrix1D class.

#include <iostream>
#include <vector>
using namespace std;

class Matrix1D {
private:
    int rows, cols;
    vector<int> data;

public:
    Matrix1D(int r, int c) : rows(r), cols(c), data(r * c, 0) {}

    int& operator()(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw out_of_range("Index out of range");
        }
        return data[i * cols + j];
    }

    int operator()(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw out_of_range("Index out of range");
        }
        return data[i * cols + j];
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << (*this)(i, j) << " ";
            }
            cout << endl;
        }
    }

    // Matrix multiplication
    Matrix1D operator*(const Matrix1D& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Matrix dimensions do not match for multiplication");
        }
        Matrix1D result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result(i, j) += (*this)(i, k) * other(k, j);
                }
            }
        }
        return result;
    }
};

int main() {
    Matrix1D mat1(2, 3);
    mat1(0, 0) = 1; mat1(0, 1) = 2; mat1(0, 2) = 3;
    mat1(1, 0) = 4; mat1(1, 1) = 5; mat1(1, 2) = 6;

    Matrix1D mat2(3, 2);
    mat2(0, 0) = 7; mat2(0, 1) = 8;
    mat2(1, 0) = 9; mat2(1, 1) = 10;
    mat2(2, 0) = 11; mat2(2, 1) = 12;

    Matrix1D result = mat1 * mat2;

    cout << "Matrix 1:" << endl;
    mat1.print();

    cout << "Matrix 2:" << endl;
    mat2.print();

    cout << "Result of multiplication:" << endl;
    result.print();

    return 0;
}


// 2. Transpose of a Matrix
// Question: Implement a function to compute the transpose of a matrix.

#include <iostream>
#include <vector>
using namespace std;

class Matrix1D {
private:
    int rows, cols;
    vector<int> data;

public:
    Matrix1D(int r, int c) : rows(r), cols(c), data(r * c, 0) {}

    int& operator()(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw out_of_range("Index out of range");
        }
        return data[i * cols + j];
    }

    int operator()(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw out_of_range("Index out of range");
        }
        return data[i * cols + j];
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << (*this)(i, j) << " ";
            }
            cout << endl;
        }
    }

    // Transpose the matrix
    Matrix1D transpose() const {
        Matrix1D result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(j, i) = (*this)(i, j);
            }
        }
        return result;
    }
};

int main() {
    Matrix1D mat(2, 3);
    mat(0, 0) = 1; mat(0, 1) = 2; mat(0, 2) = 3;
    mat(1, 0) = 4; mat(1, 1) = 5; mat(1, 2) = 6;

    cout << "Original Matrix:" << endl;
    mat.print();

    Matrix1D transposed = mat.transpose();
    cout << "Transposed Matrix:" << endl;
    transposed.print();

    return 0;
}


// 3. Sparse Matrix Addition
// Question: Implement addition for the SparseMatrix class.

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class SparseMatrix {
private:
    int rows, cols;
    vector<pair<pair<int, int>, int>> data;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    void insert(int i, int j, int value) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw out_of_range("Index out of range");
        }
        if (value != 0) {
            data.push_back({{i, j}, value});
        }
    }

    int get(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw out_of_range("Index out of range");
        }
        for (const auto& entry : data) {
            if (entry.first.first == i && entry.first.second == j) {
                return entry.second;
            }
        }
        return 0;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }

    // Add two sparse matrices
    SparseMatrix operator+(const SparseMatrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions do not match for addition");
        }
        SparseMatrix result(rows, cols);
        for (const auto& entry : data) {
            result.insert(entry.first.first, entry.first.second, entry.second);
        }
        for (const auto& entry : other.data) {
            int value = result.get(entry.first.first, entry.first.second) + entry.second;
            result.insert(entry.first.first, entry.first.second, value);
        }
        return result;
    }
};

int main() {
    SparseMatrix mat1(3, 3);
    mat1.insert(0, 0, 1);
    mat1.insert(1, 1, 2);
    mat1.insert(2, 2, 3);

    SparseMatrix mat2(3, 3);
    mat2.insert(0, 0, 4);
    mat2.insert(1, 1, 5);
    mat2.insert(2, 2, 6);

    SparseMatrix result = mat1 + mat2;

    cout << "Matrix 1:" << endl;
    mat1.print();

    cout << "Matrix 2:" << endl;
    mat2.print();

    cout << "Result of addition:" << endl;
    result.print();

    return 0;
}
