// 1.Question: Implement Binary Search in C++ and derive its time complexity expression from experimental data.

#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void deriveComplexityBinarySearch(const vector<int>& inputSizes, const vector<long long>& times) {
    cout << "Derived Time Complexity for Binary Search:" << endl;

    // Fit experimental data to T(n) = a * log2(n) + b
    double a = 0, b = 0;
    for (size_t i = 0; i < inputSizes.size(); ++i) {
        a += times[i] / log2(inputSizes[i]);
    }
    a /= inputSizes.size();
    cout << "T(n) = " << a << " * log2(n)" << endl;
}

int main() {
    vector<int> inputSizes = {1000, 5000, 10000, 20000}; // Varying input sizes
    vector<long long> binarySearchTimes;

    for (int size : inputSizes) {
        vector<int> arr(size);
        for (int i = 0; i < size; ++i) arr[i] = i; // Sorted array

        auto start = high_resolution_clock::now();
        binarySearch(arr, size - 1); // Search for the last element
        auto stop = high_resolution_clock::now();
        binarySearchTimes.push_back(duration_cast<microseconds>(stop - start).count());
    }

    deriveComplexityBinarySearch(inputSizes, binarySearchTimes);

    return 0;
}



// 2. Question: Implement Bubble Sort in C++ and derive its time complexity expression from experimental data.

#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void deriveComplexityBubbleSort(const vector<int>& inputSizes, const vector<long long>& times) {
    cout << "Derived Time Complexity for Bubble Sort:" << endl;

    // Fit experimental data to T(n) = a * n^2 + b
    double a = 0, b = 0;
    for (size_t i = 0; i < inputSizes.size(); ++i) {
        a += times[i] / (double)(inputSizes[i] * inputSizes[i]);
    }
    a /= inputSizes.size();
    cout << "T(n) = " << a << " * n^2" << endl;
}

int main() {
    vector<int> inputSizes = {1000, 5000, 10000, 20000}; // Varying input sizes
    vector<long long> bubbleSortTimes;

    for (int size : inputSizes) {
        vector<int> arr = generateRandomInput(size);
        bubbleSortTimes.push_back(measureTime([](vector<int>& arr) { bubbleSort(arr); }, arr));
    }

    deriveComplexityBubbleSort(inputSizes, bubbleSortTimes);

    return 0;
}


// 3.Question: Implement a function to count the number of inversions in an array using Merge Sort and derive its time complexity expression from experimental data.

#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    int invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; ++i) arr[i] = temp[i - left];

    return invCount;
}

int countInversions(vector<int>& arr, int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        invCount += countInversions(arr, left, mid);
        invCount += countInversions(arr, mid + 1, right);
        invCount += mergeAndCount(arr, left, mid, right);
    }
    return invCount;
}

void deriveComplexityCountInversions(const vector<int>& inputSizes, const vector<long long>& times) {
    cout << "Derived Time Complexity for Count Inversions:" << endl;

    // Fit experimental data to T(n) = a * n * log2(n) + b
    double a = 0, b = 0;
    for (size_t i = 0; i < inputSizes.size(); ++i) {
        a += times[i] / (double)(inputSizes[i] * log2(inputSizes[i]));
    }
    a /= inputSizes.size();
    cout << "T(n) = " << a << " * n * log2(n)" << endl;
}

int main() {
    vector<int> inputSizes = {1000, 5000, 10000, 20000}; // Varying input sizes
    vector<long long> countInversionsTimes;

    for (int size : inputSizes) {
        vector<int> arr = generateRandomInput(size);
        countInversionsTimes.push_back(measureTime([](vector<int>& arr) { countInversions(arr, 0, arr.size() - 1); }, arr));
    }

    deriveComplexityCountInversions(inputSizes, countInversionsTimes);

    return 0;
}
