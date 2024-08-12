#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        // Loop through 1-9
        for (int i = 0; i < 9; i++) {
            // Check for the entire column
            if (board[i][col] == ch) {
                return false;
            }
            // Check for the entire row
            if (board[row][i] == ch) {
                return false;
            }
            // Check for the entire 3x3 submatrix
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == ch) {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        // Traverse the board
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                // If an empty cell is found
                if (board[i][j] == '.') {
                    // Try every possible number (1-9)
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, i, j, ch)) {
                            // Place the number if valid
                            board[i][j] = ch;
                            // Recursively solve the rest of the board
                            if (solve(board)) {
                                return true;
                            } else {
                                // Backtrack if it doesn't lead to a solution
                                board[i][j] = '.';
                            }
                        }
                    }
                    // If no valid number is found, return false
                    return false;
                }
            }
        }
        // If the entire board is filled correctly, return true
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main() {
    // Initialize a Sudoku puzzle as a 2D vector
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    // Create an instance of the Solution class
    Solution solver;
    
    // Solve the Sudoku puzzle
    solver.solveSudoku(board);

    // Print the solved Sudoku puzzle
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
