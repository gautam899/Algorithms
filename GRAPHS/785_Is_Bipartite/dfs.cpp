#include <iostream>
#include <vector>
#include <queue>

class Solution
{
public:
    bool dfs(int start, std::vector<std::vector<int>> &graph, std::vector<int> &color)
    {
        for (auto neighbor : graph[start])
        {
            if (color[neighbor] == -1)
            {
                color[neighbor] = 1 - color[start];
                if (!dfs(neighbor, graph, color))
                    return false;
            }
            else if (color[neighbor] == color[start])
            {
                return false;
            }
        }
        return true;
    }
    bool __isBipartite(int V, std::vector<std::vector<int>> &graph)
    {
        // We would color the node the node with either 0 or 1.
        std::vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                color[i] = 1;
                if (!dfs(i, graph, color))
                    return false; // In bfs every edge is processed once. Total number of edges O(E)
            }
        }
        return true;
    }
};

int main()
{
    std::vector<std::vector<int>> graph = {{1, 2, 3},
                                           {0, 2},
                                           {0, 1, 3},
                                           {0, 2}};
    int V = 4;
    Solution sol;
    bool ans = sol.__isBipartite(V, graph);
    std::cout << ans << std::endl;
}