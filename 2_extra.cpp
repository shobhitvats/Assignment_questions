// Question: Implement Binary Search in C++.
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    int result = binarySearch(arr, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}


// Question: Implement Bubble Sort in C++.
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // Swap adjacent elements if they are in the wrong order
            }
        }
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    bubbleSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}


// Question: Implement a function to count the number of inversions in an array using Merge Sort.
#include <iostream>
#include <vector>
using namespace std;

int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    int invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // Count inversions
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

int main() {
    vector<int> arr = {8, 4, 2, 1};
    cout << "Number of inversions: " << countInversions(arr, 0, arr.size() - 1) << endl;
    return 0;
}
