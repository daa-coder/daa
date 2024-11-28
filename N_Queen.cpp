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
