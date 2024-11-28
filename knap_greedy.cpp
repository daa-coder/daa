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
