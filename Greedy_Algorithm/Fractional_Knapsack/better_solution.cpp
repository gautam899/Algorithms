#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
public:
    // Instead of storing the index, store the val, wt and the ratio so that we do not have to use val and wt repeatedly
    struct helper
    {
        int value;
        int weight;
        double ratio;
    };

    double fractionalKnapsack(std::vector<int> &val, std::vector<int> &wt, int cap)
    {
        // code here
        int n = val.size();
        std::vector<helper> items;
        for (int i = 0; i < n; i++)
        {
            items.push_back({val[i], wt[i], static_cast<double>(val[i]) / wt[i]});
        }

        std::sort(items.begin(), items.end(), [](const auto &a, const auto &b)
                  { return a.ratio > b.ratio; });

        int remaining = cap;
        double ans = 0.0;
        for (const auto &it : items)
        {
            if (remaining == 0)
                break;

            if (remaining - it.weight >= 0)
            {
                ans += it.value;
                remaining -= it.weight;
            }
            else
            {
                ans += remaining * it.ratio; // Last item to pick
                break;
            }
        }
        return ans;
    }
};

int main()
{
    std::vector<int> val = {60, 100, 120};
    std::vector<int> wt = {10, 20, 30};
    Solution sol;
    double ans = sol.fractionalKnapsack(val, wt, 50);
    std::cout << ans << std::endl;
    return 0;
}
