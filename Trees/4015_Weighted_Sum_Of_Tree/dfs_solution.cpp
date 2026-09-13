#include <vector>
#include <queue>
#include <algorithm>

class Solution
{
public:
    using ll = long long;
    int findDepth(const std::vector<int> &parent, std::vector<int> &depth, int node)
    {
        if (node == 0)
            return 1;

        if (depth[node] != 0)
            return depth[node];

        // 1 + depth of the parent(which is already evaluated)
        depth[node] = 1 + findDepth(parent, depth, parent[node]);

        return depth[node];
    }

    ll weightedSum(const std::vector<int> &parent, const std::vector<int> &nums)
    {
        int n = parent.size();

        std::vector<int> depth(n, 0);
        depth[0] = 1;
        for (size_t i = 0; i < n; i++)
        {
            findDepth(parent, depth, i);
        }

        int maxDepth = *std::max_element(depth.begin(), depth.end());
        // Evaluate the Sum.
        ll ans = 0;
        for (size_t i = 0; i < n; i++)
        {
            ans += (ll)nums[i] * (maxDepth - depth[i] + 1);
        }
        return ans;
    }
};