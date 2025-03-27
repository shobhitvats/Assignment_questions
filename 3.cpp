#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
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
void measureTime(Func sortFunction, vector<int>& arr, const string& sortName) {
    auto start = high_resolution_clock::now();
    sortFunction(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by " << sortName << ": " << duration.count() << " microseconds" << endl;
}

int main() {
    srand(time(0)); // Seed for random number generation

    vector<int> inputSizes = {1000, 5000, 10000, 20000}; // Varying input sizes

    for (int size : inputSizes) {
        cout << "\nInput Size: " << size << endl;

        vector<int> arr = generateRandomInput(size);

        // Measure Selection Sort
        vector<int> arr1 = arr;
        measureTime([](vector<int>& arr) { selectionSort(arr); }, arr1, "Selection Sort");

        // Measure Insertion Sort
        vector<int> arr2 = arr;
        measureTime([](vector<int>& arr) { insertionSort(arr); }, arr2, "Insertion Sort");

        // Measure Merge Sort
        vector<int> arr3 = arr;
        measureTime([](vector<int>& arr) { mergeSort(arr, 0, arr.size() - 1); }, arr3, "Merge Sort");

        // Measure Quick Sort
        vector<int> arr4 = arr;
        measureTime([](vector<int>& arr) { quickSort(arr, 0, arr.size() - 1); }, arr4, "Quick Sort");
    }

    return 0;
}
