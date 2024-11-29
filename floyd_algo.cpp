// Implement Al Pair Shortest paths problem using Floyd's Algorithm.

// Djikstras is not used for negative cycles while Floyd's Algorithm detects negative cycle;

// In the code we have adjancy matrix and algo will have 3 loops

// if same vertex such as adj[1][1] add 0
// if no edge between vertex add -1; represents INF;
#include <iostream>
#include <vector>
using namespace std;

void print_mat(const vector<vector<int> >& adj){
    int n = adj.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1e9)
                cout << "INF ";
            else
                cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void floyd(vector<vector<int> >& adj) {
    int n = adj.size();

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0; j < n ; j++) {
            if(adj[i][j] == -1)
                adj[i][j] = 1e9;
            if(i == j)
                adj[i][j] = 0;
        }
    }
    
    for(int k = 0 ; k < n ; k++) {
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0; j < n ; j++) {
                if (adj[i][k] < 1e9 && adj[k][j] < 1e9)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }   
        }
    }

    for(int i = 0 ; i < n ; i++) { 
        if(adj[i][i] < 0){
            cout << "Negative cycle detected!!" << endl;
            return;
        }
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0; j < n ; j++) {
            if(adj[i][j] == 1e9)
                adj[i][j] = -1;
        }
    }
}

int main() {
    int n;
    cout << "Enter the matix size : ";
    cin >> n;
    vector<vector<int> > vec(n, vector<int>(n));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            // add values;
            cout << "Enter the value of adj -> "  << i << ", "  << j << " : ";
            cin >> vec[i][j];
        }
    }

    floyd(vec);

    // Print the final shortest path matrix
    cout << "The shortest path matrix is:\n";
    print_mat(vec);

    return 0;
}

// TC = O(n^3)
// SC = O(n^2)


// TC = o(n3)
// SC = o(n2)

//Algorithm
//Input the number of vertices n and the adjacency matrix graph.
// Initialize dist to graph.
// For each intermediate vertex k (0 to n-1):
// For each source vertex i (0 to n-1):
// For each destination vertex j (0 to n-1):
// Update dist[i][j] if a shorter path through k is found.
// Print the final distance matrix.
