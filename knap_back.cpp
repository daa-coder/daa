//Implement 0/1 Knapsack problem using Following algorithmic strategies.
//(b) Back tracking

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int backtrack(int ind, int bag, vector<int> &val, vector<int> &wt) {
    if(ind == 0) {
        if(wt[ind] <= bag)
            return val[ind];
        return 0;
    }

    // notpick
    int notpick = backtrack(ind - 1, bag, val, wt);

    // pick
    int pick = -1e9;
    if (wt[ind] <= bag) {
        int pick = val[ind] + backtrack(ind - 1, bag - wt[ind], val, wt);
    }
    return max(pick, notpick);
}

int main() {
    int n, w;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++){
        cout << "Enter weight of item " << i + 1 << ": ";
        cin >> wt[i];
        cout << "Enter value of item " << i + 1 << ": ";
        cin >> val[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> w;

    int res = backtrack(n-1, w, val, wt);

    cout << "Maximum value in the knapsack: " << res << endl;

    return 0;
}

// Time Complexity: O(2^n)
// Space Complexity: O(n)   recursion stack;


// Time Complexity: O(2^n)
// Space Complexity: O(n)   recursion stack;

//algorithm
// Input:

// Read the number of items n.
// Read the arrays wt[] (weights) and val[] (values) of size n.
// Read the knapsack capacity w.
// Function:

// Define the recursive function backtrack(ind, bag):
// If ind == 0, check if the weight of the first item is less than or equal to the current capacity:
// If yes, return the value of the item.
// If no, return 0.
// Otherwise, calculate two possible cases:
// Not picking the item: Recursively call backtrack(ind - 1, bag).
// Picking the item (if it fits): Return val[ind] + backtrack(ind - 1, bag - wt[ind]).
// Return the maximum of the two cases.
// Result:

// Call backtrack(n-1, w) to compute the maximum achievable value.
// Output the result.
