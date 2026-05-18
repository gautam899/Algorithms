#include <iostream>
#include <queue>

class Solution
{
public:
    void bfs(int r, int c, std::vector<std::vector<char>> &grid, int rows, int cols)
    {
        std::queue<std::pair<int, int>> q;
        grid[r][c] = 1;
        q.push({r, c});
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nr = a + delr[i];
                int nc = b + delc[i];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1')
                {
                    grid[nr][nc] = '0';
                    q.push({nr, nc});
                }
            }
        }
    }

    int number_of_Island(std::vector<std::vector<char>> &grid)
    {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        std::vector<std::vector<int>> visited(rows, std::vector<int>(cols, 0));
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                // If it's not visited already and is land, we found an island.
                if (grid[r][c] == '1' && !visited[r][c])
                {
                    count++;
                    bfs(r, c, grid, rows, cols);
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