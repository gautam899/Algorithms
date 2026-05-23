#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Solution
{
public:
    std::vector<int> find_toposort(int V, std::vector<std::vector<int>> &edges)
    {
        std::vector<std::vector<int>> adj(V);
        std::vector<int> indegree(V, 0);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        std::queue<int> q;
        std::vector<int> toposort;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                toposort.push_back(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto neighbor : adj[node])
            {
                if (--indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                    toposort.push_back(neighbor);
                }
            }
        }
        if (toposort.size() != V)
        {
            printf("Cycle detected!. No toposort possible");
            exit(1);
        }
        return toposort;
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