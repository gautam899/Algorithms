#include <iostream>
#include <vector>

class Solution
{
public:
    bool dfs(int start, std::vector<std::vector<int>> &adj, std::vector<int> &visited, int parent)
    {
        visited[start] = 1;

        for (auto neighbor : adj[start])
        {
            if (!visited[neighbor])
            {
                if (dfs(neighbor, adj, visited, start))
                    return true;
            }
            else if (neighbor != parent)
                return true;
        }
        return false;
    }

    bool __has_cycle(int V, std::vector<std::vector<int>> &edges)
    {
        // Create a adjacency matrix
        std::vector<std::vector<int>> adj(V);
        for (auto it : edges) // For every edge, 2 insertions are done. Hence, O(E).
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        std::vector<int> visited(V, 0); // Space: O(V)
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                // Inside dfs every vertex is processed once and every every edge is processed twice.
                if (dfs(i, adj, visited, -1))
                    return true;
            }
        }
        return false;
        // Time Complexity: O(V+E)
    }
};
int main()
{
    std::vector<std::vector<int>> edges = {{0, 1},
                                           {0, 2},
                                           {1, 2},
                                           {2, 3}};
    int V = 4;
    Solution sol;
    bool ans = sol.__has_cycle(V, edges);
    std::cout << ans << "\n";
    return 0;
}