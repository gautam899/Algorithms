class Solution {
public:
    bool isSafe(int r, int c, int num, vector<vector<char>>& board) {
        // Check for row
        for (int i = 0; i < 9; i++) {
            if (board[r][i] - '0' == num) {
                return false;
            }
        }
        // Check for the column
        for (int i = 0; i < 9; i++) {
            if (board[i][c] - '0' == num) {
                return false;
            }
        }
        // Check for the cell of 3x3
        int start_r = (r / 3) * 3;
        int start_c = (c / 3) * 3;
        for (int i = start_r; i < start_r + 3; i++) {
            for (int j = start_c; j < start_c + 3; j++) {
                if (board[i][j] - '0' == num)
                    return false; // Number already exist in the cell.
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board) {
        // Iterate the board and fill the indexes
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // If the current cell is empty.
                if (board[row][col] == '.') {
                    for (int i = 1; i <= 9; i++) {
                        if (isSafe(row, col, i, board)) {
                            board[row][col] = '0' + i;
                            if (helper(board) == true) {
                                return true;
                            }
                            // If not true, then backtrack
                            board[row][col] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid number fits.
                }
            }
        }
        // If we scanned the entire board and did not find an empty cell. Return
        // true
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        // The problem can be solved using recursion and backtracking. For every
        // empty cell we have options from 1-9. But before pushing in a element
        // in a cell, we want to make sure that it is safe to do so. How?. Check
        // for the current row, col and current cell is the element is occuring
        // more that one.

        // Base case: What could it be?
        // If we iterate the complete board and do not find a singel empty cell we found a solution. Return true. 
        helper(board);
    }
};
