// Solve the following instance of the knapsack problem given the knapsack capacity in w=20 using greedy methods,
// Total no. of item is 5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter the n : ";
    cin >> n;
    vector<int> weight(n);
    vector<int> values(n);
    for(int i = 0 ; i < n ; i++){
        cout << "Enter the weight " << i+1 << " : ";
        cin >> weight[i];
        cout << "Enter the values " << i+1 << " : ";
        cin >> values[i];
    }
    int w;
    cout << "Enter the sack weight : ";
    cin >> w;

    vector<pair<double, int > > p;
    for(int i = 0; i < n; i++){
        double ratio = (double)values[i] / weight[i];
        p.push_back(make_pair(ratio, i));
    }
    
    // Sort by value-to-weight ratio in descending order
    sort(p.begin(), p.end(), greater<pair<double, int > >());
    
    double ans = 0;
    
    
    for(int i = 0; i < n; i++){
        double ratio = p[i].first;
        int idx = p[i].second;
        
        if(w >= weight[idx]){
            ans += values[idx];
            w -= weight[idx];
        }
        else {
            ans += ratio * w;
            break;
        }
    }
    
    cout << "Maximum value in Knapsack = " << ans << endl;
    return 0;
}

// TC = O(nlogn)
// SC = O(n)


/ TC = O(nlogn)
// SC = O(n)

//algorithm
// Input:

// Read the number of items n.
// Read the weight and value of each item into the arrays weight[] and values[].
// Read the knapsack capacity w.
// Calculate the Value-to-Weight Ratio:

// For each item, compute the ratio value[i] / weight[i] and store it in a vector p as a pair (ratio, index).
// Sort Items by Ratio:

// Sort the vector p in descending order based on the ratio using the sort() function with a custom comparison (greater<pair<double, int>>).
// Greedy Selection of Items:

// Initialize the variable ans = 0 to store the total value in the knapsack.
// For each item (sorted by value-to-weight ratio):
// If the item can fully fit into the knapsack, add its full value to ans and reduce the remaining capacity of the knapsack.
// If the item can't fully fit, take as much as possible (fraction of the value) and stop.
// Output:

// Print the total value ans that can be obtained with the given knapsack capacity.
