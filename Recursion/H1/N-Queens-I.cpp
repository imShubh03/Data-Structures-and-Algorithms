#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int duprow = row;
        int dupcol = col;

        // Check for upper back diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = duprow;
        col = dupcol;
        // Check for previous columns in the same row
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        row = duprow;
        col = dupcol;
        // Check for lower back diagonal
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
        // Base case
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                // Backtrack
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, board, ans, n);
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 4; // You can change the value of n to test different board sizes
    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "Total number of solutions for " << n << "-Queens: " << solutions.size() << endl;

    for (const auto& solution : solutions) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
