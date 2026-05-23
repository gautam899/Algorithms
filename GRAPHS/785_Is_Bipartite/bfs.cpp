#include <iostream>
#include <vector>
#include <queue>

class Solution
{
public:
    bool bfs(int start, std::vector<std::vector<int>> &graph, std::vector<int> &color)
    {
        std::queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            int c = color[node];
            for (auto neighbor : graph[node])
            {
                if (color[neighbor] == 0)
                {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                }
                else if (color[node] == color[neighbor])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool __isBipartite(int V, std::vector<std::vector<int>> &graph)
    {
        // We would color the node the node with either 1 or 2.
        std::vector<int> color(V, -1);
        bool ans = true;
        for (int i = 0; i < V; i++) // O(V).
        {
            if (color[i] == -1)
            {
                color[i] = 1;
                if (!bfs(i, graph, color))
                    return false; // In bfs every edge is processed once. Total number of edges O(E)
            }
        }
        return true;
        // Total time complexity: O(V+E).
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