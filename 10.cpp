#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Matrix {
private:
    int rows, cols;
    vector<vector<int>> data;

public:
    // Constructor to initialize the matrix
    Matrix(int r, int c, const vector<vector<int>>& values) : rows(r), cols(c), data(values) {
        if (values.size() != r || (r > 0 && values[0].size() != c)) {
            throw invalid_argument("Invalid matrix dimensions");
        }
    }

    // Get the number of rows
    int getRows() const {
        return rows;
    }

    // Get the number of columns
    int getCols() const {
        return cols;
    }

    // Add two matrices
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions do not match for addition");
        }
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return Matrix(rows, cols, result);
    }

    // Subtract two matrices
    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions do not match for subtraction");
        }
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return Matrix(rows, cols, result);
    }

    // Multiply two matrices
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

    // Transpose the matrix
    Matrix transpose() const {
        vector<vector<int>> result(cols, vector<int>(rows, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[j][i] = data[i][j];
            }
        }
        return Matrix(cols, rows, result);
    }

    // Print the matrix
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

    Matrix transposed = m1.transpose();
    cout << "Transpose of Matrix 1:" << endl;
    transposed.print();

    return 0;
}
