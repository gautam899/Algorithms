#include <iostream>
#include <vector>

class Solution
{
public:
    void dfs(int r, int c, std::vector<std::vector<char>> &grid, int rows, int cols)
    {
        grid[r][c] = -1;
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nr = r + delr[i];
            int nc = c + delc[i];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1')
            {
                dfs(nr, nc, grid, rows, cols);
            }
        }
    }
    int number_of_Island(std::vector<std::vector<char>> &grid)
    {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        // We do not actually need a visited vector.
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++) // The nested loops takes O(r*c) time.
            {
                if (grid[r][c] == '1')
                {
                    count++;
                    dfs(r, c, grid, rows, cols);
                }
            }
        }
        return count;
    }
};
int main()
{
    std::vector<std::vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    Solution sol;
    int ans = sol.number_of_Island(grid);
    std::cout << ans << std::endl;
    return 0;
}