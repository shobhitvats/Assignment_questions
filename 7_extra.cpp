// 1.Question: Implement Binary Search in C++ to search for a laptop in a sorted list by price.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Laptop {
    string brand;
    string model;
    double price;

    bool operator<(const Laptop& other) const {
        return price < other.price;
    }
};

int binarySearch(const vector<Laptop>& laptops, double targetPrice) {
    int left = 0, right = laptops.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (laptops[mid].price == targetPrice) {
            return mid;
        } else if (laptops[mid].price < targetPrice) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<Laptop> laptops = {
        {"Dell", "XPS 13", 1200},
        {"Apple", "MacBook Pro", 2000},
        {"HP", "Spectre x360", 900},
        {"Lenovo", "ThinkPad X1", 1500},
        {"Asus", "ROG Zephyrus", 1800}
    };

    // Sort laptops by price
    sort(laptops.begin(), laptops.end());

    double targetPrice;
    cout << "Enter the price to search: ";
    cin >> targetPrice;

    int index = binarySearch(laptops, targetPrice);
    if (index != -1) {
        cout << "Laptop found: " << laptops[index].brand << " " << laptops[index].model << endl;
    } else {
        cout << "No laptop found with the given price." << endl;
    }

    return 0;
}


// 2. Question: Implement Bubble Sort in C++ to sort a list of laptops by RAM.

#include <iostream>
#include <vector>
using namespace std;

struct Laptop {
    string brand;
    string model;
    int ram;

    void display() const {
        cout << "Brand: " << brand << ", Model: " << model << ", RAM: " << ram << "GB" << endl;
    }
};

void bubbleSort(vector<Laptop>& laptops) {
    int n = laptops.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (laptops[j].ram > laptops[j + 1].ram) {
                swap(laptops[j], laptops[j + 1]);
            }
        }
    }
}

int main() {
    vector<Laptop> laptops = {
        {"Dell", "XPS 13", 16},
        {"Apple", "MacBook Pro", 8},
        {"HP", "Spectre x360", 32},
        {"Lenovo", "ThinkPad X1", 16},
        {"Asus", "ROG Zephyrus", 64}
    };

    bubbleSort(laptops);

    cout << "Laptops sorted by RAM:" << endl;
    for (const auto& laptop : laptops) {
        laptop.display();
    }

    return 0;
}


// 3. Question: Implement Merge Sort in C++ to sort a list of laptops by storage.

#include <iostream>
#include <vector>
using namespace std;

struct Laptop {
    string brand;
    string model;
    int storage;

    void display() const {
        cout << "Brand: " << brand << ", Model: " << model << ", Storage: " << storage << "GB" << endl;
    }
};

void merge(vector<Laptop>& laptops, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Laptop> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) L[i] = laptops[left + i];
    for (int j = 0; j < n2; ++j) R[j] = laptops[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].storage <= R[j].storage) {
            laptops[k] = L[i];
            i++;
        } else {
            laptops[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        laptops[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        laptops[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Laptop>& laptops, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(laptops, left, mid);
        mergeSort(laptops, mid + 1, right);
        merge(laptops, left, mid, right);
    }
}

int main() {
    vector<Laptop> laptops = {
        {"Dell", "XPS 13", 512},
        {"Apple", "MacBook Pro", 256},
        {"HP", "Spectre x360", 1024},
        {"Lenovo", "ThinkPad X1", 512},
        {"Asus", "ROG Zephyrus", 2048}
    };

    mergeSort(laptops, 0, laptops.size() - 1);

    cout << "Laptops sorted by storage:" << endl;
    for (const auto& laptop : laptops) {
        laptop.display();
    }

    return 0;
}
