
// 1. Selection Sort

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Find the index of the smallest element
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]); // Swap with the smallest element
        }
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    selectionSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
// 2. Insertion Sort

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i]; // Current element to be inserted
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift elements to the right
            j--;
        }
        arr[j + 1] = key; // Insert the key in the correct position
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    insertionSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
// 3. Merge Sort

#include <iostream>
#include <vector>
using namespace std;

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
        mergeSort(arr, left, mid);      // Sort left half
        mergeSort(arr, mid + 1, right); // Sort right half
        merge(arr, left, mid, right);  // Merge the two halves
    }
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
// 4. Quick Sort

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of the smaller element

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // Swap if the current element is smaller than the pivot
        }
    }
    swap(arr[i + 1], arr[high]); // Place the pivot in the correct position
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition the array
        quickSort(arr, low, pi - 1);       // Sort the left subarray
        quickSort(arr, pi + 1, high);      // Sort the right subarray
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
