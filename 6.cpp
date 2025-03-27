#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to generate random input
vector<int> generateRandomInput(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000; // Random numbers between 0 and 9999
    }
    return arr;
}

// Function to measure execution time
template <typename Func>
long long measureTime(Func sortFunction, vector<int>& arr) {
    auto start = high_resolution_clock::now();
    sortFunction(arr);
    auto stop = high_resolution_clock::now();
    return duration_cast<microseconds>(stop - start).count();
}

// Function to derive time complexity expression
void deriveComplexity(const string& sortName, const vector<int>& inputSizes, const vector<long long>& times) {
    cout << "Derived Time Complexity for " << sortName << ":" << endl;

    // Fit experimental data to a complexity model
    if (sortName == "Selection Sort" || sortName == "Insertion Sort") {
        // Theoretical complexity: O(n^2)
        // Fit to T(n) = a * n^2 + b
        double a = 0, b = 0;
        for (size_t i = 0; i < inputSizes.size(); ++i) {
            a += times[i] / (double)(inputSizes[i] * inputSizes[i]);
        }
        a /= inputSizes.size();
        cout << "T(n) = " << a << " * n^2" << endl;
    } else if (sortName == "Merge Sort" || sortName == "Quick Sort") {
        // Theoretical complexity: O(n log n)
        // Fit to T(n) = a * n * log2(n) + b
        double a = 0, b = 0;
        for (size_t i = 0; i < inputSizes.size(); ++i) {
            a += times[i] / (double)(inputSizes[i] * log2(inputSizes[i]));
        }
        a /= inputSizes.size();
        cout << "T(n) = " << a << " * n * log2(n)" << endl;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    vector<int> inputSizes = {1000, 5000, 10000, 20000}; // Varying input sizes

    // Measure Selection Sort
    vector<long long> selectionSortTimes;
    for (int size : inputSizes) {
        vector<int> arr = generateRandomInput(size);
        selectionSortTimes.push_back(measureTime([](vector<int>& arr) { selectionSort(arr); }, arr));
    }
    deriveComplexity("Selection Sort", inputSizes, selectionSortTimes);

    // Measure Insertion Sort
    vector<long long> insertionSortTimes;
    for (int size : inputSizes) {
        vector<int> arr = generateRandomInput(size);
        insertionSortTimes.push_back(measureTime([](vector<int>& arr) { insertionSort(arr); }, arr));
    }
    deriveComplexity("Insertion Sort", inputSizes, insertionSortTimes);

    // Measure Merge Sort
    vector<long long> mergeSortTimes;
    for (int size : inputSizes) {
        vector<int> arr = generateRandomInput(size);
        mergeSortTimes.push_back(measureTime([](vector<int>& arr) { mergeSort(arr, 0, arr.size() - 1); }, arr));
    }
    deriveComplexity("Merge Sort", inputSizes, mergeSortTimes);

    // Measure Quick Sort
    vector<long long> quickSortTimes;
    for (int size : inputSizes) {
        vector<int> arr = generateRandomInput(size);
        quickSortTimes.push_back(measureTime([](vector<int>& arr) { quickSort(arr, 0, arr.size() - 1); }, arr));
    }
    deriveComplexity("Quick Sort", inputSizes, quickSortTimes);

    return 0;
}
