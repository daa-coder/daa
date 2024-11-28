// Implementation hte folowing
//algorithm using Divide&Conquer method.
//(b) Quick Sort
//Also display execution time for different size of input and perform the analysis.

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

// Function to perform Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high]; // Choose the last element as the pivot
        int i = (low - 1);     // Index of smaller element

        // Partitioning the array
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]); // Place pivot in its correct position
        int pi = i + 1;

        // Recursively sort the left and right subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to analyze the execution time of Quick Sort for different input sizes
void analyzeQuickSort() {
    vector<int> input_sizes = {100, 1000, 5000, 10000, 50000, 100000};
    vector<double> execution_times;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100000);

    cout << "Analyzing Quick Sort performance:\n";

    for (size_t i = 0; i < input_sizes.size(); i++) {
        int size = input_sizes[i];
        vector<int> arr(size);
        generate(arr.begin(), arr.end(), [&] { return dis(gen); }); // Generate random input

        auto start = high_resolution_clock::now();
        quickSort(arr, 0, size - 1);
        auto end = high_resolution_clock::now();

        double time_taken = duration_cast<duration<double>>(end - start).count();
        execution_times.push_back(time_taken);

        cout << "Input size: " << size << ", Execution time: " << time_taken << " seconds" << endl;
    }
}

// Function to allow manual entry of an array and perform Quick Sort
void manualInputQuickSort() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array before sorting: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Array after sorting: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to choose between analysis and manual input
int main() {
    int choice;
    cout << "Choose an option:\n";
    cout << "1. Analyze Quick Sort performance\n";
    cout << "2. Manually enter an array for Quick Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        analyzeQuickSort();
    } else if (choice == 2) {
        manualInputQuickSort();
    } else {
        cout << "Invalid choice. Exiting program.\n";
    }

    return 0;
}

// Time Complexity: 𝑂(𝑛log𝑛) (Best/Average), 𝑂(𝑛^2) (Worst case)
// Space Complexity: 𝑂(log𝑛) (Best/Average), 𝑂(𝑛) (Worst case)
