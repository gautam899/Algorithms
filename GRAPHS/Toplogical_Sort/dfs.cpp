#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Solution
{
public:
    void dfs(int node, int V, std::vector<std::vector<int>> &adj, std::vector<int> &visited, std::vector<int> &ans)
    {
        visited[node] = true;

        for (auto neighbor : adj[node]) // Every edge is processed once O(E)
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, V, adj, visited, ans);
            }
        }
        // Push the node once all the nodes that are reachable to the curr node are visited.
        ans.push_back(node);
    }
    std::vector<int> find_toposort(int V, std::vector<std::vector<int>> &edges)
    {
        std::vector<std::vector<int>> adj(V);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
        }
        std::vector<int> ans;
        std::vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) // Every vertex is processed once. O(V)
        {
            if (!visited[i])
            {
                dfs(i, V, adj, visited, ans);
            }
        }
        // If we observe carefully, ans vector currently contains reverse topological.
        std::reverse(ans.begin(), ans.end()); // O(VLogV) worst case.
        return ans;
        // Time complexity: O(V+E) + O(VLogV)
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
    std::vector<int> ans = sol.find_toposort(V, edges);
    for (auto it : ans)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    return 0;
}