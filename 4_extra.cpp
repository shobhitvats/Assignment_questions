// 1. Question: Implement Binary Search in C++ and compare its experimental execution time with its theoretical time complexity.

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
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

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;

    auto start = high_resolution_clock::now();
    int result = binarySearch(arr, target);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    cout << "Time taken by Binary Search: " << duration.count() << " microseconds" << endl;

    // Theoretical time complexity is O(log n)
    int n = arr.size();
    long long theoreticalTimeValue = log2(n);
    cout << "Theoretical Time for Binary Search: " << theoreticalTimeValue << " units" << endl;
    cout << "Experimental vs Theoretical Ratio: " << (double)duration.count() / theoreticalTimeValue << endl;

    return 0;
}


// 2. Question: Implement Bubble Sort in C++ and compare its experimental execution time with its theoretical time complexity.

#include <iostream>
#include <vector>
#include <chrono>
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

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    auto start = high_resolution_clock::now();
    bubbleSort(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    cout << "Time taken by Bubble Sort: " << duration.count() << " microseconds" << endl;

    // Theoretical time complexity is O(n^2)
    int n = arr.size();
    long long theoreticalTimeValue = n * n;
    cout << "Theoretical Time for Bubble Sort: " << theoreticalTimeValue << " units" << endl;
    cout << "Experimental vs Theoretical Ratio: " << (double)duration.count() / theoreticalTimeValue << endl;

    return 0;
}


// 3.Question: Implement a function to count the number of inversions in an array using Merge Sort and compare its experimental execution time with its theoretical time complexity.

#include <iostream>
#include <vector>
#include <chrono>
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

int main() {
    vector<int> arr = {8, 4, 2, 1};

    auto start = high_resolution_clock::now();
    int invCount = countInversions(arr, 0, arr.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Number of inversions: " << invCount << endl;
    cout << "Time taken by Count Inversions: " << duration.count() << " microseconds" << endl;

    // Theoretical time complexity is O(n log n)
    int n = arr.size();
    long long theoreticalTimeValue = n * log2(n);
    cout << "Theoretical Time for Count Inversions: " << theoreticalTimeValue << " units" << endl;
    cout << "Experimental vs Theoretical Ratio: " << (double)duration.count() / theoreticalTimeValue << endl;

    return 0;
}
