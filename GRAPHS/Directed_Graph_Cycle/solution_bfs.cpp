#include <iostream>
#include <queue>

class Solution
{
public:
    // To find if a cycle exist in directed graph using bfs, we cannot use the usual approach.
    // We can topological sort to find if there is topo sort possible. According to the property of topological sort,
    // a topo sort is only possible when there is no cycle.
    bool __has_cycle(int V, std::vector<std::vector<int>> &edges)
    {
        std::vector<std::vector<int>> adj(V);
        std::vector<int> indegree(V, 0);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        // In a directed graph, the sum of lengths of all adjacency list is E, where E is the number of edges.

        std::queue<int> q;
        // We start with indegree 0
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int visited = 0;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            visited++; // Keep a count of all the indegree zero.
            for (auto neighbor : adj[x])
            {
                if (--indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }
        // No cycle, if we are able to visit all the vertices.
        return visited == V;
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