// 1. Question: Implement Binary Search in C++ and determine the maximum input size it can handle within a 1-second execution time limit.

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

int calculateMaxInputSizeBinarySearch(long long timeLimitMicroseconds) {
    // Theoretical time complexity: O(log n)
    // Solve for n: log2(n) = timeLimitMicroseconds
    return static_cast<int>(pow(2, timeLimitMicroseconds));
}

int main() {
    long long timeLimitMicroseconds = 1e6; // 1 second in microseconds

    cout << "Theoretical Maximum Input Size for Binary Search (1-second limit): "
         << calculateMaxInputSizeBinarySearch(timeLimitMicroseconds) << endl;

    return 0;
}


// 2. Question: Implement Bubble Sort in C++ and determine the maximum input size it can handle within a 2-minute execution time limit.

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

int calculateMaxInputSizeBubbleSort(long long timeLimitMicroseconds) {
    // Theoretical time complexity: O(n^2)
    // Solve for n: n^2 = timeLimitMicroseconds
    return static_cast<int>(sqrt(timeLimitMicroseconds));
}

int main() {
    long long timeLimitMicroseconds = 2 * 60 * 1e6; // 2 minutes in microseconds

    cout << "Theoretical Maximum Input Size for Bubble Sort (2-minute limit): "
         << calculateMaxInputSizeBubbleSort(timeLimitMicroseconds) << endl;

    return 0;
}


// 3. Question: Implement a function to count the number of inversions in an array using Merge Sort and determine the maximum input size it can handle within a 3-minute execution time limit.

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

int calculateMaxInputSizeCountInversions(long long timeLimitMicroseconds) {
    // Theoretical time complexity: O(n log n)
    // Use binary search to solve for n: n log n = timeLimitMicroseconds
    int low = 1, high = 1e9;
    while (low < high) {
        int mid = low + (high - low) / 2;
        long long timeEstimate = mid * log2(mid);
        if (timeEstimate < timeLimitMicroseconds) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    long long timeLimitMicroseconds = 3 * 60 * 1e6; // 3 minutes in microseconds

    cout << "Theoretical Maximum Input Size for Count Inversions (3-minute limit): "
         << calculateMaxInputSizeCountInversions(timeLimitMicroseconds) << endl;

    return 0;
}
