#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the minimum cost edge from the current city
int findMinCostCity(int currentCity, const vector<vector<int>>& dist, vector<bool>& visited) {
    int n = dist.size();
    int minCost = INT_MAX;
    int nextCity = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[currentCity][i] < minCost) {
            minCost = dist[currentCity][i];
            nextCity = i;
        }
    }
    return nextCity;
}

int tspGreedy(const vector<vector<int>>& dist) {
    int n = dist.size();
    vector<bool> visited(n, false);
    int totalCost = 0;
    int currentCity = 0; // Start from city 0

    visited[currentCity] = true;
    cout << "Path: " << currentCity;

    // Visit all cities once
    for (int count = 1; count < n; count++) {
        int nextCity = findMinCostCity(currentCity, dist, visited);
        if (nextCity == -1) {
            cout << "\nError: No valid path found!" << endl;
            return -1; // Error in case no valid path exists
        }
        visited[nextCity] = true;
        totalCost += dist[currentCity][nextCity];
        currentCity = nextCity;
        cout << " -> " << currentCity;
    }

    // Return to the starting city
    totalCost += dist[currentCity][0];
    cout << " -> " << 0 << endl;

    return totalCost;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter the distance matrix (use a large value for no direct edge, e.g., 1e9):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    int cost = tspGreedy(dist);
    if (cost != -1) {
        cout << "The total cost of the TSP path is: " << cost << endl;
    }
    return 0;
}


// Example Input
// Enter the number of cities: 4
// Enter the distance matrix (use a large value for no direct edge, e.g., 1e9):
// 0 10 15 20
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0

// Time Complexity:
// O(n²): The algorithm visits each city once, and for each city, it finds the minimum cost edge among unvisited cities.
// Space Complexity:
// O(n): To store the visited cities and the current state.


// Algorithm
// Start at an Initial City: Select any city as the starting point (e.g., city 0).
// Visit the Nearest Unvisited City: From the current city, choose the nearest city that hasn't been visited yet (based on minimum distance).
// Mark the City as Visited: Add the chosen city to the tour and mark it as visited.
// Repeat Until All Cities Are Visited: Continue the process until all cities have been visited.
// Return to the Starting City: Once all cities are visited, return to the starting city to complete the tour.



