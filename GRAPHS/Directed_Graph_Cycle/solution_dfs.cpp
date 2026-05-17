#include <iostream>
#include <vector>

// We can perform a dfs traversal by keeping a visited array and saying that if we encounterd a node
// already visited, then there is a cycle detected. Is this entirely correct? No
// We could be visiting a already visited node but the dfs originating from a different node. This will give us a cycle, even when there is not.
// To fix this problem, we create 3 states for a node, un-visited, processing/visiting, completed/done.
// If we encounter a node which is already under processing in the same dfs recursion, then we can say that we encounterd a cycle.
class Solution
{
public:
    bool dfs(int start, std::vector<std::vector<int>> &adj, std::vector<int> &visited)
    {
        // mark the node processing
        visited[start] = 1; // Each vertex visited once. O(V)

        for (auto neighbor : adj[start]) // Each directed edge explored once O(E)
        {
            if (!visited[neighbor])
            {
                if (dfs(neighbor, adj, visited))
                    return true;
            }
            else if (visited[neighbor] == 1)
            {
                return true; // encounterd a already visited node in the current recursion.
            }
        }

        visited[start] = 2; // processed the entire adj list for node start.
        return false;
    }
    bool __has_cycle(int V, std::vector<std::vector<int>> &edges)
    {
        std::vector<std::vector<int>> adj(V);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
        }

        std::vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i]) // This ensure each node enters the dfs once overall.
            {
                if (dfs(i, adj, visited))
                {
                    return true;
                }
            }
        }
        // Time complexity of DFS O(V+E)
        return false;
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