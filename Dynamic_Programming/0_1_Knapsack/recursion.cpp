#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int solve(int ind, int W, std::vector<int> &val, std::vector<int> &wt)
    {
        if (ind == val.size() || W == 0)
            return 0;

        int not_pick = solve(ind + 1, W, val, wt);

        int pick = -1;
        if (wt[ind] <= W)
        {
            pick = val[ind] + solve(ind + 1, W - wt[ind], val, wt);
        }
        return std::max(pick, not_pick);
    }
    int knapsack(int W, std::vector<int> &val, std::vector<int> &wt)
    {
        // code here
        int n = val.size();
        return solve(0, W, val, wt);
    }
};

int main()
{
    int W = 4;
    std::vector<int> val = {1, 2, 3};
    std::vector<int> wt = {4, 5, 1};
    Solution sol;
    int ans = sol.knapsack(W, val, wt);
    std::cout << ans << std::endl;
    return 0;
}