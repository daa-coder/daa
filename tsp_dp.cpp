#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX; // Define a large value (infinity) to represent unreachable paths

// Function to solve TSP using Dynamic Programming with Bit Masking
int tsp(int mask, int pos, int n, const vector<vector<int>>& dist, vector<vector<int>>& dp) {
    // If all cities have been visited (mask represents all cities visited), return the distance back to the starting city
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // Return to the starting city (city 0)
    }

    // If this state has been already computed, return the stored result to avoid recomputation
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF; // Initialize the answer as infinity (large value)
    
    // Explore all the cities that haven't been visited yet
    for (int city = 0; city < n; city++) {
        // If the city hasn't been visited yet (checked by bitmasking)
        if ((mask & (1 << city)) == 0) {
            // Recurse by visiting the new city and updating the mask
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, n, dist, dp);
            ans = min(ans, newAns); // Update the answer with the minimum distance
        }
    }

    // Store the computed result in the DP table and return it
    return dp[mask][pos] = ans;
}

int main() {
    int n; // Number of cities
    cout << "Enter the number of cities: ";
    cin >> n; // Input the number of cities

    vector<vector<int>> dist(n, vector<int>(n)); // Distance matrix to store the distance between cities
    cout << "Enter the distance matrix:\n"; 
    // Input the distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j]; // Input the distance between city i and city j
        }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, -1)); // DP table to store subproblem solutions
    // The table size is (2^n) x n, where (2^n) represents all possible combinations of visited cities

    // Call the TSP function starting from city 0 with only city 0 visited (mask = 1)
    cout << "The minimum cost is: " << tsp(1, 0, n, dist, dp) << endl; // Output the minimum cost

    return 0;
}


// TC : n^2.2^n
// SC: 2^n. n


// Theory 
// The Traveling Salesman Problem (TSP) using Dynamic Programming (DP) employs bitmasking to represent the set of visited cities and a DP table to store the minimum cost for each state (visited cities and current city). 
// The recursive function explores all possible cities to visit next, minimizing the travel cost. 
// The time complexity is O(n * 2^n), where n is the number of cities, and the space complexity is also O(n * 2^n) due to the DP table storing results for each subset of cities and each city. 
// This approach significantly reduces the complexity compared to brute force methods.
