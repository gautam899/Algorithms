#include <vector>
#include <queue>
#include <algorithm>

class Solution
{
public:
    using ll = long long;
    int findDepth(const std::vector<int> &parent, std::vector<int> &depth,
                  int node)
    {
        std::vector<int> path;
        const int origNode = node;
        // Backtrack to the node that has its depth already evaluated
        while (depth[node] == 0)
        {
            path.push_back(node);

            if (node == 0)
            {
                break;
            }

            node = parent[node];
        }

        // At this moment we are standing at a node that has it's depth already
        // evaluated
        int currDepth = depth[node];

        // Backfill the depth while moving toward the root.
        for (auto it = path.rbegin(); it != path.rend(); ++it)
        {
            depth[*it] = ++currDepth;
        }

        return depth[origNode]; // Keep store of original node. and simply doing
                                // path.front() might yield a undefined binding
                                // to null pointer of type int.
    }
    ll weightedSum(std::vector<int> &parent, std::vector<int> &nums)
    {
        const size_t n = parent.size();

        std::vector<int> depth(n, 0);
        depth[0] = 1;

        int maxDepth = 1;
        for (size_t i = 0; i < n; i++)
        {
            maxDepth = std::max(maxDepth,
                                findDepth(parent, depth, static_cast<int>(i)));
        }

        ll ans = 0;

        for (size_t i = 0; i < n; i++)
        {
            const ll weight = static_cast<ll>(maxDepth - depth[i] + 1);
            ans += static_cast<ll>(nums[i]) * weight;
        }
        return ans;
    }
};