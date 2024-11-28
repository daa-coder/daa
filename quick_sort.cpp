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

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void analyzeQuickSort() {
    vector<int> input_sizes = {100, 1000, 5000, 10000, 50000, 100000};
    vector<double> execution_times;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100000);

    for (size_t i = 0; i < input_sizes.size(); i++) {
        int size = input_sizes[i];
        vector<int> arr(size);
        generate(arr.begin(), arr.end(), [&] { return dis(gen); });

        auto start = high_resolution_clock::now();
        quickSort(arr, 0, size - 1);
        auto end = high_resolution_clock::now();

        double time_taken = duration_cast<duration<double> >(end - start).count();
        execution_times.push_back(time_taken);

        cout << "Input size: " << size << ", Execution time: " << time_taken << " seconds" << endl;
    }
}

int main() {
    analyzeQuickSort();
    return 0;
}

// Time Complexity: 𝑂(𝑛log𝑛) (Best/Average), 𝑂(𝑛^2) (Worst case)
// Space Complexity: 𝑂(log𝑛) (Best/Average), 𝑂(𝑛) (Worst case)
