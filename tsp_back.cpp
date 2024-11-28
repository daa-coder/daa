// TSP using backtracking
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX; // Define a large value to represent infinity

// Function to solve the TSP problem using backtracking
void tspBacktracking(int graph[][10], vector<bool>& visited, int n, int pos, int count, int cost, int& minCost) {
    // If all cities are visited and there is a path back to the starting city
    if (count == n && graph[pos][0]) {
        // Update the minimum cost of the tour
        minCost = min(minCost, cost + graph[pos][0]);
        return;
    }

    // Explore all cities from the current city
    for (int i = 0; i < n; i++) {
        // If the city is not visited and there's a path to it
        if (!visited[i] && graph[pos][i]) {
            visited[i] = true; // Mark the city as visited
            // Recursively visit the next city
            tspBacktracking(graph, visited, n, i, count + 1, cost + graph[pos][i], minCost);
            visited[i] = false; // Backtrack by unmarking the city
        }
    }
}

int main() {
    int n; // Number of cities
    cout << "Enter the number of cities: ";
    cin >> n;

    int graph[10][10]; // Adjacency matrix representing the cost graph
    cout << "Enter the cost matrix (enter 0 if no path exists):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j]; // Input the cost matrix
        }
    }

    vector<bool> visited(n, false); // Array to track visited cities
    visited[0] = true; // Start the tour from the first city

    int minCost = INF; // Initialize the minimum cost to infinity
    // Call the backtracking function starting from the first city
    tspBacktracking(graph, visited, n, 0, 1, 0, minCost);

    // Output the result
    if (minCost == INF) {
        cout << "No solution exists for the given input." << endl;
    } else {
        cout << "The minimum cost of TSP is: " << minCost << endl;
    }

    return 0;
}

// Time Complexity (TC):
// Worst Case: O(n!) because we explore all permutations of the cities.
// Here, 'n' is the number of cities.

// Space Complexity (SC):
// O(n) due to the visited array, which tracks the cities visited during the recursion.


// Sample input -> 
// Enter the number of cities: 4
// Enter the cost matrix (enter 0 if no path exists):
// 0 10 15 20
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0

// The minimum cost of TSP is: 80
