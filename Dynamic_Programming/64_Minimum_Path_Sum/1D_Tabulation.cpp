#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

/*
    dp[r][c] = grid[r][c] + std::min(dp[r+1][c], dp[r][c+1]);
    So, at a time, we are only using 2 rows. The curr and next.
    If we are at row = r, we are never going to use r+2. Hence, using a dp[row][col] is storing a lot of
    extra information.
*/
class Solution
{
public:
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        std::vector<int> curr(col, 0);
        std::vector<int> next(col, 0);
        int ans = INT_MAX;
        for (int r = row - 1; r >= 0; r--)
        {
            for (int c = col - 1; c >= 0; c--)
            {
                if (r == row - 1 && c == col - 1)
                {
                    curr[c] = grid[r][c];
                }
                else
                {
                    int down = INT_MAX;
                    if (r + 1 < row)
                    {
                        down = next[c];
                    }
                    int right = INT_MAX;
                    if (c + 1 < col)
                    {
                        right = curr[c + 1];
                    }
                    curr[c] = grid[r][c] + std::min(down, right);
                }
            }
            next = curr;
        }
        return curr[0];
        // Time complexity: O(N^2), Space Complexity: O(N).
    }
};

int main()
{
    return 0;
}