// Find a subset of a given set S= {sl ,s2 ,...,s n} of n positive integers whose sum is equal to a given positive integer d. 
// For example, fi S- {1, 2, 5, 6, 8} and d=9there are two solutions {1,2,6} and {1,8). 
// Asuitable messagesi ot be displayed fi the given Problem instance doesn't have asolution.

// The problem subarray/subsequence sum of k ;
// is the pattern present or not that sum up to k;
// if found print the subsets;   else print not found;

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// subset function
void f(int ind, int tar, vector<int>& arr, vector<int>& curr, vector<vector<int> >& res, vector<vector<int> >& dp) {
    if(tar == 0) {
        res.push_back(curr);
        return;
    }

    if(ind == 0) {
        if(arr[ind] == tar){
            curr.push_back(arr[ind]);
            res.push_back(curr);
            curr.pop_back();  // backtrack;
        }
        return;
    }

    if (dp[ind][tar] != -1) {
        // allready added to result;
        return;
    }
// not take case:
    f(ind - 1, tar, arr, curr, res, dp);

// take case:
    if (arr[ind] <= tar) {
        curr.push_back(arr[ind]);
        f(ind - 1, tar - arr[ind], arr, curr, res, dp);
        curr.pop_back();  // backtrack..
    }

    dp[ind][tar] = 1;
}

int main() {

    vector<int> arr;
    vector<vector<int> > res;
    vector<int> curr;
    int n, k, val;
    cout << "Enter the size of array : ";
    cin >> n;

    for(int i = 0 ; i < n ; i++) {
        cout << "Enter the val " << i+1 << " : ";
        cin >> val;
        arr.push_back(val);
    }

    cout << "Enter the value of k : ";
    cin >> k;
    vector<vector<int> > dp(n, vector<int>(k+1, -1));
    
    f(n-1, k, arr, curr, res, dp);

    if (res.empty()) {
        cout << "No subsets found that sum to " << k << endl;
    } 
    else {
        cout << "Subsets are:" << endl;
        for (auto& subset : res) {
            for (int num : subset) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
 
    return 0;
}

// Time Complexity : O(n * k);
// Space Complexity : O(n * k) + O(n) ..(Auxiliary stack space :)