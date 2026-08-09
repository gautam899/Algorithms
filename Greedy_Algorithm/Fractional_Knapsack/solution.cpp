#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
public:
    struct helper
    {
        int index;
        double val_per_w;
    };

    double fractionalKnapsack(std::vector<int> &val, std::vector<int> &wt, int cap)
    {
        // code here
        int n = val.size();
        std::vector<helper> items;
        for (int i = 0; i < n; i++)
        {
            double val_w = (double)val[i] / wt[i];
            items.push_back({i, val_w});
        }

        std::sort(items.begin(), items.end(), [](const auto &a, const auto &b)
                  { return a.val_per_w > b.val_per_w; });

        int curr_w = 0;
        double ans = 0.0;
        for (int i = 0; i < n; i++)
        {
            int j = items[i].index; // original index
            if (curr_w + wt[j] <= cap)
            { // can pick the whole
                ans += (double)val[j];
                curr_w += wt[j];
            }
            else
            {
                ans += (double)(cap - curr_w) / wt[j] * val[j];
                curr_w = cap;
            }
        }
        return ans;
        // TC: O(NlogN)
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
