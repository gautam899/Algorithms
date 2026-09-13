#include <vector>
#include <queue>
#include <algorithm>

class Solution
{
public:
    using ll = long long;
    long long weightedSum(std::vector<int> &parent, std::vector<int> &nums)
    {
        int n = parent.size();
        std::vector<std::vector<int>> adj(n);

        // Build the tree
        for (int i = 1; i < n; i++)
        {
            adj[parent[i]].push_back(i);
        }

        // Evaluate the depth of each node using BFS and keep track of the maximum depth.
        std::vector<int> depth(n, 0);
        std::queue<int> q;
        int maxD = -1e9;
        depth[0] = 1;
        q.push(0);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (node != 0)
            {
                depth[node] = depth[parent[node]] + 1;
            }
            maxD = std::max(maxD, depth[node]);
            for (const auto child : adj[node])
            {
                q.push(child);
            }
        }

        // Evaluate the Sum.
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (ll)nums[i] * (maxD - depth[i] + 1);
        }
        return ans;
    }
};
