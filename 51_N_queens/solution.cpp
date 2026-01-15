class Solution {
public:
    bool isValid(int r, int c, vector<string>& board, int n) {
        // Check for the same column
        for (int i = 1; i <= r; i++) {
            if (board[r - i][c] == 'Q')
                return false;
        }

        // Check for left diagonal. Move left diagonally upward a minimum of r
        // or c
        for (int i = 1; i <= min(r, c); i++) {
            if (board[r - i][c - i] == 'Q')
                return false;
        }

        // Check right diagonally upward
        for (int i = 1; i <= min(r, n - c - 1); i++) {
            if (board[r - i][c + i] == 'Q')
                return false;
        }

        // If no conflicts return true.
        return true;
    }
    void helper(int r, vector<string>& board, vector<vector<string>>& ans, int n) {
        if (r == board.size()) // We found a arrangement such that no queen
                               // attacks each other.
        {
            ans.push_back(board); // Note: Once we find one arrangement, another arrangement is the mirror of the one that is found.
            return;
        }
        // For every queen we have 0->r-1 number of options
        for (int col = 0; col < n; col++) {
            if (isValid(r, col, board, n)) {
                board[r][col] = 'Q';
                helper(r + 1, board, ans, n); // Move to the next row.
                board[r][col] = '.';       // backtrack
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // Base cases.
        vector<vector<string>> ans;
        vector<string> res(n, string(n, '.'));
        if (n == 1)
            return {{"Q"}};
        if (n == 2 || n == 3)
            return ans; // No possible way to put queens such that no queen
                        // attacks each other.
        helper(0, res, ans, n);
        return ans;
    }
};
