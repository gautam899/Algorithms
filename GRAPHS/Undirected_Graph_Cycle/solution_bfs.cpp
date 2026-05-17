#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Solution
{
public:
    bool bfs(int start, std::vector<std::vector<int>> &adj, std::vector<int> &vis, int V)
    {
        // When creating a queue, we must keep track of the parent of node that we are currenly visiting
        std::queue<std::pair<int, int>> q;
        q.push({start, -1});
        vis[start] = 1;
        while (!q.empty())
        {
            int x = q.front().first;
            int parent = q.front().second;
            q.pop();
            // Visit all the neighbor of x.
            for (auto neighbor : adj[x]) // O(2E). The entire adjacency list contains 2E entries.
            {
                if (vis[neighbor] == 1 && neighbor != parent) // If already visited, not a parent of neighbor, return true(has cycle)
                {
                    return true;
                }
                vis[neighbor] = 1;
                q.push({neighbor, x});
            }
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
            // Every vertex is processed once in the bfs because of visited constraint.
            // And an edge is examined twice. Therefore, TC: O(V+2E) ~= O(V+E)
            if (visited[i] == 0)
            {
                if (bfs(i, adj, visited, V) == true)
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