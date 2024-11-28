// Asuitable messagesi ot be displayed fi the given Problem instance doesn't have asolution.
// Implement any scheme ot find the optimal solution for the Traveling Salesperson problem and then solve hte 
//same problem instance using different algorithmic strategies and determine the optimal solution.

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define inf (int)1e5
#define N 4

using namespace std;

// Node class to represent each state of the solution space
class Node
{
public:
    vector<vector<int>> reducedMat; // The matrix after row and column reductions
    vector<int> path;                // The path of visited cities
    int cost;                        // Current cost of the path
    int level;                       // Level of the node in the search tree (depth)
    int parent;                      // Parent city (from which we came)
    int currVertex;                  // Current city we are visiting

    // Constructor to initialize a node
    Node(vector<vector<int>> rootMat, vector<int> rootPath, int rootCost, int rootLevel, int i, int j)
    {
        reducedMat = rootMat;    // Set the reduced matrix
        path = rootPath;         // Set the current path
        cost = rootCost;         // Set the current cost
        level = rootLevel;       // Set the current level
        parent = i;              // Set the parent city
        currVertex = j;          // Set the current city

        path.push_back(j);       // Add the current city to the path

        // Modify the reduced matrix to reflect the new state
        if (parent != -1)
        {
            for (int k = 0; k < N; ++k)
            {
                reducedMat[parent][k] = inf; // Remove parent city from all other cities
                reducedMat[k][currVertex] = inf; // Remove the path from current city to all other cities
            }
            reducedMat[currVertex][0] = inf; // Remove the path back to the starting city
        }
    }

    // Copy constructor
    Node(const Node &other)
    {
        reducedMat = other.reducedMat;
        path = other.path;
        cost = other.cost;
        level = other.level;
        parent = other.parent;
        currVertex = other.currVertex;
    }
};

// Custom comparator for the priority queue (min-heap)
struct min_heap
{
    bool operator()(Node *a, Node *b)
    {
        return a->cost > b->cost; // We want the node with the smallest cost to have the highest priority
    }
};

// Function to calculate the reduced cost (lower bound) for a node
int calculateCost(Node *curr)
{
    vector<vector<int>> mat = curr->reducedMat;
    int parent = curr->parent;
    int currVertex = curr->currVertex;
    int totalCost = 0;

    // Row reduction (subtract the minimum element from each row)
    for (int i = 0; i < N; ++i)
    {
        int mini = inf;
        for (int j = 0; j < N; ++j)
        {
            mini = min(mini, mat[i][j]);
        }
        if (mini != inf)
        {
            for (int j = 0; j < N; ++j)
            {
                if (mat[i][j] != inf)
                    mat[i][j] -= mini; // Subtract the minimum from all elements in the row
            }
            totalCost += mini; // Add the reduction cost
        }
    }

    // Column reduction (subtract the minimum element from each column)
    for (int i = 0; i < N; ++i)
    {
        int mini = inf;
        for (int j = 0; j < N; ++j)
        {
            mini = min(mini, mat[j][i]);
        }
        if (mini != inf)
        {
            for (int j = 0; j < N; ++j)
            {
                if (mat[j][i] != inf)
                    mat[j][i] -= mini; // Subtract the minimum from all elements in the column
            }
            totalCost += mini; // Add the reduction cost
        }
    }

    curr->reducedMat = mat; // Update the reduced matrix

    return totalCost; // Return the total reduction cost
}

// Function to solve the Traveling Salesman Problem using Branch and Bound
Node solve(vector<vector<int>> &mat)
{
    priority_queue<Node *, vector<Node *>, min_heap> pq; // Min-heap priority queue for nodes
    vector<int> path; // Path to keep track of the visited cities
    Node *root = new Node(mat, path, 0, 0, -1, 0); // Create the root node (starting from city 0)
    root->cost = calculateCost(root); // Calculate the reduced cost of the root node
    pq.push(root); // Push the root node into the priority queue
    int ans = inf; // Variable to store the minimum cost found
    Node ansNode = *root; // Variable to store the node with the optimal solution

    // While there are nodes to explore in the priority queue
    while (!pq.empty())
    {
        Node *curr = pq.top(); // Get the node with the minimum cost
        pq.pop(); // Remove the node from the queue
        if (curr->level == N - 1) // If we have reached the last city (N-1)
        {
            if (curr->cost < ans) // If the current node has a better cost
            {
                ans = curr->cost; // Update the minimum cost
                ansNode = *curr;  // Update the optimal solution node
            }
            delete curr; // Delete the current node to free memory
            continue;
        }
        if (curr->cost < ans) // If the current cost is less than the best solution so far
        {
            for (int i = 0; i < N; ++i)
            {
                int parent = curr->currVertex;
                if (curr->reducedMat[parent][i] != inf) // If the city i is not removed
                {
                    Node *child = new Node(curr->reducedMat, curr->path, 0, curr->level + 1, parent, i); // Create a child node
                    int childReducedCost = calculateCost(child); // Calculate the reduced cost of the child node
                    child->cost = curr->cost + childReducedCost; // Update the child's total cost
                    if (curr->reducedMat[parent][i] != inf)
                    {
                        child->cost += curr->reducedMat[parent][i]; // Add the direct cost to the child node
                    }
                    pq.push(child); // Push the child node into the priority queue
                }
            }
        }
        delete curr; // Delete the current node to free memory
    }
    return ansNode; // Return the node with the optimal solution
}

int main()
{
    // Example matrix of distances between cities
    vector<vector<int>> mat = {{inf, 4, 9, 5},
                               {6, inf, 4, 8},
                               {9, 4, inf, 9},
                               {5, 8, 9, inf}};
    Node ans = solve(mat); // Call the solve function to get the optimal solution
    cout << "The optimal cost of TSP is : " << ans.cost << endl; // Output the optimal cost
    cout << "The optimal path is : ";
    for (auto ele : ans.path) // Output the optimal path
        cout << ele << " ";
    cout << endl;
    return 0;
}

// Time Complexity (TC): The time complexity of the Branch and Bound approach can be as high as 𝑂(𝑁!) in the worst case, where  N is the number of cities.
// However, pruning the search space with bounds can improve performance.

// Space Complexity (SC): O(N^2), due to storing the matrix and the search tree nodes.
