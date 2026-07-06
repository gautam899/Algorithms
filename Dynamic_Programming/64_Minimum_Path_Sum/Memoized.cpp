#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
class Solution
{
public:
    int solve(int r, int c, int rows, int cols, std::vector<std::vector<int>> &grid, std::vector<std::vector<int>> &dp)
    {
        // Base case. If we reach the bottom right
        if (r == rows - 1 && c == cols - 1)
        {
            return grid[r][c];
        }
        // what is dp[r][c] here? Starting from r,c what is already evaluated minimum sum path to index
        // rows-1, cols-1.
        if (dp[r][c] != -1)
        {
            return dp[r][c];
        }
        // Down
        int down = INT_MAX;
        if (r + 1 < rows)
        {
            down = grid[r][c] + solve(r + 1, c, rows, cols, grid, dp);
        }
        // Right
        int right = INT_MAX;
        if (c + 1 < cols)
        {
            right = grid[r][c] + solve(r, c + 1, rows, cols, grid, dp);
        }
        return dp[r][c] = std::min(right, down);
    }
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        std::vector<std::vector<int>> dp(row, std::vector<int>(col, -1));
        return solve(0, 0, row, col, grid, dp);
    }
};