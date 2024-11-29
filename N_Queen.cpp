#include <bits/stdc++.h>
using namespace std;

// Function to check if placing a queen at (row, col) is safe
bool isSafe(int row, int col, vector<string> &board, int n) {
    int dupRow = row, dupCol = col;

    // Check upper diagonal on the left side
    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    // Check left side
    row = dupRow;
    col = dupCol;
    while (col >= 0) {
        if (board[row][col] == 'Q') return false;
        col--;
    }

    // Check lower diagonal on the left side
    row = dupRow;
    col = dupCol;
    while (row < n && col >= 0) {
        if (board[row][col] == 'Q') return false;
        row++;
        col--;
    }

    return true;
}

// Recursive function to solve N-Queens problem
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
    // If all queens are placed
    if (col == n) {
        ans.push_back(board);
        return;
    }

    // Try placing a queen in each row for the current column
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';  // Place the queen
            solve(col + 1, board, ans, n);  // Solve for the next column
            board[row][col] = '.';  // Backtrack and remove the queen
        }
    }
}

// Function to solve the N-Queens problem and return all arrangements
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));  // Initialize the board with '.'
    solve(0, board, ans, n);
    return ans;
}

int main() {
    int n;  // Size of the chessboard (4x4 grid) and number of queens
    cout<<"Enter no. of queens: ";
    cin>>n;

    vector<vector<string>> ans = solveNQueens(n);

    // Print all the arrangements
    for (int i = 0; i < ans.size(); i++) {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}

// TC: O(N⋅N!)
// SC:O(N^2 +N+N^2⋅N!)

//Time Complexity: In the worst case, the time complexity is O(N!)O(N!) because, in the worst case, you might need to place queens in each of the N columns for each of the N rows.
//Space Complexity: O(N2)O(N^2), which is required to store the N×N chessboard.

//algorithm
// Input: Read the integer n, which denotes the size of the board (n×n).

// Initialization:

// Create an empty result list res to store all valid board configurations.
// Initialize an n×n board filled with '.' (empty spaces).
// Create three tracking arrays:
// left[]: Tracks if a row is occupied by a queen.
// up[]: Tracks if a major diagonal is occupied.
// down[]: Tracks if a minor diagonal is occupied.
// Backtracking Function:

// Start from the first column (col = 0).
// For each row in the current column:
// If placing a queen at the current row and column does not cause any conflicts (i.e., no other queen is in the same row, same major diagonal, or same minor diagonal):
// Place the queen.
// Update the left[], up[], and down[] arrays to mark the row and diagonals as occupied.
// Move to the next column (col + 1).
// If a solution is found (i.e., queens are placed in all columns), store the board configuration in the result list.
// Backtrack by removing the queen and unmarking the row and diagonals.
// If all rows in the current column have been tried and no solution found, backtrack to the previous column.
// Return the Result: After backtracking completes, the result list res will contain all valid solutions.

// Output:

// If the result list res is empty, output "No solution exists."
// Otherwise, print the number of solutions and display each solution.
