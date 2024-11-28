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
