#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

// Function to swap elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function for Quicksort
int partition(vector<int>& arr, int low, int high) {
   int pivot=arr[low];

    int i=low, j=high;

    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }

        while(arr[j]>pivot && j>=low+1){
            j--;
        }

        if(i<j){
            swap(arr[i],arr[j]);
        }

    }
        swap(arr[low], arr[j]);
        return j;
}

// Quicksort implementation
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Mergesort merge function
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

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

// Mergesort implementation
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> data(500);
    srand(time(0));
    for (int i = 0; i < 500; i++) {
        data[i] = rand() % 1000; // Random numbers between 0 and 999
    }

    vector<int> dataForQuickSort = data;
    vector<int> dataForMergeSort = data;

    // Measure time for Quicksort
    auto startQuick = chrono::high_resolution_clock::now();
    quickSort(dataForQuickSort, 0, dataForQuickSort.size() - 1);
    auto endQuick = chrono::high_resolution_clock::now();
    auto quickSortTime = chrono::duration_cast<chrono::microseconds>(endQuick - startQuick).count();

    // Measure time for Mergesort
    auto startMerge = chrono::high_resolution_clock::now();
    mergeSort(dataForMergeSort, 0, dataForMergeSort.size() - 1);
    auto endMerge = chrono::high_resolution_clock::now();
    auto mergeSortTime = chrono::duration_cast<chrono::microseconds>(endMerge - startMerge).count();

    // Display the results
    cout << "Time taken by Quicksort: " << quickSortTime << " microseconds" << endl;
    // cout << "Time taken by Mergesort: " << mergeSortTime << " microseconds" << endl;

    // for(int i=0; i<500; i++){
    //     cout << dataForQuickSort[i] << " ";
    // }

    return 0;
}
