//Implement 0/1 Knapsack problem using Following algorithmic strategies.
//(a) Dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int memo(int ind, vector<int> &val, vector<int> &wt, vector<vector<int> > &dp, int bag) {
    if (ind == 0) {
        if (wt[ind] <= bag)
            return val[0];
        return 0;
    }

    if (dp[ind][bag] != -1)
        return dp[ind][bag];

    int notpick = 0 + memo(ind - 1, val, wt, dp, bag);
    int pick = -1e9;
    if (wt[ind] <= bag){
        pick = val[ind] + memo(ind - 1, val, wt, dp, bag - wt[ind]);
    }

    return dp[ind][bag] = max(pick, notpick);
}

int main() {
    int n;
    cout << "Enter the number of items : ";
    cin >> n;

    vector<int> weight(n), values(n);
    for (int i = 0; i < n; i++){
        cout << "Enter the weight of item " << i + 1 << ": ";
        cin >> weight[i];
        cout << "Enter the value of item " << i + 1 << ": ";
        cin >> values[i];
    }

    int w;
    cout << "Enter the knapsack capacity: ";
    cin >> w;

    // create a dp array of size n and w+1
    vector<vector<int> > dp(n, vector<int>(w + 1, -1));

    // using memoization
    int ans = memo(n - 1, values, weight, dp, w);

    cout << "Maximum value in Knapsack = " << ans << endl;

    return 0;
}

// Time Complexity (TC): O(n * w), where n is the number of items and w is the knapsack capacity.
// Space Complexity (SC): O(n * w), due to the storage required for the dynamic programming table.
