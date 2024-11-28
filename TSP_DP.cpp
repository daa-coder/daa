#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int tsp(int mask, int pos, int n, const vector<vector<int>>& dist, vector<vector<int>>& dp) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // Return to the starting city
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;
    for (int city = 0; city < n; city++) {
        // If the city is not visited
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, n, dist, dp);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    int n; // Number of cities
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, -1)); // DP table
    cout << "The minimum cost is: " << tsp(1, 0, n, dist, dp) << endl;

    return 0;
}

TC : n^2.2^n
SC: 2^n. n
