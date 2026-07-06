#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
class Solution
{
public:
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        std::vector<std::vector<int>> dp(row, std::vector<int>(col, 0));

        for (int r = row - 1; r >= 0; r--)
        {
            for (int c = col - 1; c >= 0; c--)
            {
                if (r == row - 1 && c == col - 1)
                {
                    dp[r][c] = grid[r][c];
                }
                else
                {
                    int down = INT_MAX;
                    if (r + 1 < row)
                    {
                        down = dp[r + 1][c];
                    }
                    int right = INT_MAX;
                    if (c + 1 < col)
                    {
                        right = dp[r][c + 1];
                    }
                    dp[r][c] = grid[r][c] + std::min(down, right);
                }
            }
        }
        return dp[0][0];
        // Time complexity: O(N^2) and space complexity O(N^2)
    }
};