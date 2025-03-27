#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Polynomial {
private:
    vector<double> coefficients; // Coefficients of the polynomial

public:
    // Constructor to initialize the polynomial
    Polynomial(const vector<double>& coeffs) : coefficients(coeffs) {
        if (coeffs.empty()) {
            throw invalid_argument("Coefficients cannot be empty");
        }
    }

    // Evaluate the polynomial at a given value of x
    double evaluate(double x) const {
        double result = 0.0;
        double power = 1.0;
        for (double coeff : coefficients) {
            result += coeff * power;
            power *= x;
        }
        return result;
    }

    // Add two polynomials
    Polynomial operator+(const Polynomial& other) const {
        vector<double> resultCoeffs(max(coefficients.size(), other.coefficients.size()), 0.0);
        for (size_t i = 0; i < coefficients.size(); ++i) {
            resultCoeffs[i] += coefficients[i];
        }
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            resultCoeffs[i] += other.coefficients[i];
        }
        return Polynomial(resultCoeffs);
    }

    // Subtract two polynomials
    Polynomial operator-(const Polynomial& other) const {
        vector<double> resultCoeffs(max(coefficients.size(), other.coefficients.size()), 0.0);
        for (size_t i = 0; i < coefficients.size(); ++i) {
            resultCoeffs[i] += coefficients[i];
        }
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            resultCoeffs[i] -= other.coefficients[i];
        }
        return Polynomial(resultCoeffs);
    }

    // Multiply two polynomials
    Polynomial operator*(const Polynomial& other) const {
        vector<double> resultCoeffs(coefficients.size() + other.coefficients.size() - 1, 0.0);
        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(resultCoeffs);
    }

    // Print the polynomial
    void print() const {
        for (size_t i = 0; i < coefficients.size(); ++i) {
            if (i > 0) {
                cout << " + ";
            }
            cout << coefficients[i];
            if (i > 0) {
                cout << "x^" << i;
            }
        }
        cout << endl;
    }
};

int main() {
    Polynomial p1({1, 2, 3}); // 1 + 2x + 3x^2
    Polynomial p2({4, 5});     // 4 + 5x

    cout << "Polynomial 1: ";
    p1.print();
    cout << "Polynomial 2: ";
    p2.print();

    Polynomial sum = p1 + p2;
    cout << "Sum: ";
    sum.print();

    Polynomial diff = p1 - p2;
    cout << "Difference: ";
    diff.print();

    Polynomial prod = p1 * p2;
    cout << "Product: ";
    prod.print();

    double x = 2.0;
    cout << "Evaluation of Polynomial 1 at x = " << x << ": " << p1.evaluate(x) << endl;

    return 0;
}
