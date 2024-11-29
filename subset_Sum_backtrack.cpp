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


// TC: 2^n
// SC: n

//algorithm
// Input:

// The size of the set (n), and the target sum (targetSum).
// The set of integers that need to be considered for finding subsets.
// Recursive Backtracking Approach:

// Base Case 1: If the sum of the current subset (currentSum) equals the target sum (targetSum), print the current subset.
// Base Case 2: If the currentSum exceeds targetSum or we have considered all elements (i.e., index equals the size of the set), stop the recursion for the current path.
// Recursive Case:
// First, try including the current element in the subset and recurse further.
// Then, backtrack: exclude the current element from the subset and recurse again with the updated state.
// Backtrack:

// As we explore different subsets, we backtrack by undoing the inclusion of an element and continuing the exploration of other subsets.
// Stopping Condition:

// If the current subset sum exceeds the target sum or we have exhausted all elements, we backtrack and try other possibilities.
// Output:

// If one or more valid subsets are found, display them.
// If no valid subset is found, print a message indicating so.
