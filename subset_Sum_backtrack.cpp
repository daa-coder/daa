#include <iostream>
#include <vector>

using namespace std;

// Function to find all subsets that sum up to a given value
void findSubsets(const vector<int>& set, vector<int>& currentSubset, int index, int currentSum, int targetSum) {
    // If the current sum is equal to the target sum, print the current subset
    if (currentSum == targetSum) {
        cout << "{ ";
        for (int i : currentSubset) {
            cout << i << " ";
        }
        cout << "}" << endl;
        return ;
    }

    // If the sum exceeds the target sum, stop further exploration
    if (currentSum > targetSum || index == set.size()) {
        return;
    }

    // Include the current element in the subset and recurse
    currentSubset.push_back(set[index]);
    findSubsets(set, currentSubset, index + 1, currentSum + set[index], targetSum);

    // Backtrack: exclude the current element from the subset and recurse
    currentSubset.pop_back();
    findSubsets(set, currentSubset, index + 1, currentSum, targetSum);
}

int main() {
    int n, targetSum;
    // Input the number of elements in the set and the target sum
    cout << "Enter the number of elements in the set: ";
    cin >> n;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    vector<int> set(n);
    // Input the elements of the set
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    // Vector to store the current subset
    vector<int> currentSubset;
    // Find and print all subsets whose sum is equal to the target sum
    findSubsets(set, currentSubset, 0, 0, targetSum);

    return 0;
}

// TC: 2^n
// SC: n
