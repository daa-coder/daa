// Implement 0/1 Knapsack problem using Following algorithmic strategies.
//(C) Branch and bound


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Structure to store information about an item
struct Item {
    int weight, profit;
    double profitWeightRatio;
};

// Structure to represent a node in the decision tree
struct Node {
    int level;  // Index of the current item
    int profit; // Profit so far
    int weight; // Weight so far
    double bound; // Upper bound on profit
};

// Custom comparator for max-heap (priority queue)
struct CompareBound {
    bool operator()(Node const& a, Node const& b) {
        return a.bound < b.bound; // Higher bound gets higher priority
    }
};

// Function to calculate the upper bound on the maximum profit
double calculateBound(Node u, int n, int W, vector<Item>& items) {
    if (u.weight >= W)
        return 0; // If weight exceeds capacity, bound is 0

    double profitBound = u.profit;
    int totalWeight = u.weight;

    // Start from the next level and add items to the knapsack
    for (int i = u.level + 1; i < n && totalWeight + items[i].weight <= W; i++) {
        totalWeight += items[i].weight;
        profitBound += items[i].profit;
    }

    // Add fractional part of the next item if the knapsack is not full
    if (u.level + 1 < n) {
        int remainingWeight = W - totalWeight;
        profitBound += remainingWeight * items[u.level + 1].profitWeightRatio;
    }

    return profitBound;
}

// Comparator function to sort items based on profit/weight ratio
bool cmp(Item a, Item b) {
    return a.profitWeightRatio > b.profitWeightRatio;
}

// Function to solve the 0/1 Knapsack problem using Branch and Bound
int knapsackBranchAndBound(int n, int W, vector<Item>& items) {
    // Sort items by profit/weight ratio
    sort(items.begin(), items.end(), cmp);

    // Initialize the priority queue (max heap) with custom comparator
    priority_queue<Node, vector<Node>, CompareBound> pq;

    // Create the root node
    Node root = {-1, 0, 0, 0};
    root.bound = calculateBound(root, n, W, items);

    // Push the root node to the priority queue
    pq.push(root);

    int maxProfit = 0;

    // Branch and Bound algorithm
    while (!pq.empty()) {
        Node u = pq.top();
        pq.pop();

        // If bound of u is less than maxProfit, skip this node
        if (u.bound <= maxProfit)
            continue;

        // Explore the next level (include/exclude the next item)
        Node v;

        // Case 1: Include the next item
        v.level = u.level + 1;
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].profit;

        if (v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit; // Update maxProfit
        }

        v.bound = calculateBound(v, n, W, items);
        if (v.bound > maxProfit) {
            pq.push(v);
        }

        // Case 2: Exclude the next item
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = calculateBound(v, n, W, items);

        if (v.bound > maxProfit) {
            pq.push(v);
        }
    }

    return maxProfit;
}

int main() {
    int n, W;

    // Input number of items and maximum weight
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    vector<Item> items(n);

    // Input the weights and profits of items
    for (int i = 0; i < n; i++) {
        cout << "Enter weight and profit of item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].profit;
        items[i].profitWeightRatio = (double)items[i].profit / items[i].weight;
    }

    // Solve the problem using Branch and Bound
    int maxProfit = knapsackBranchAndBound(n, W, items);

    // Output the maximum profit
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}

// Time Complexity (TC): 𝑂(2^n) in the worst case (due to the decision tree exploration).
// Space Complexity (SC): 𝑂(𝑛+2𝑛) in the worst case (for storing items and decision tree nodes).
// Expected Answer: The maximum profit achievable by the 0/1 knapsack using Branch and Bound depends on the input values (number of items, weights, profits, and knapsack capacity).





