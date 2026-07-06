#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int solve(int ind, int W, std::vector<int> &val, std::vector<int> &wt, std::vector<std::vector<int>> &dp)
    {
        if (ind == val.size() || W == 0)
            return 0;

        if (dp[ind][W] != -1)
            return dp[ind][W];
        int not_pick = solve(ind + 1, W, val, wt, dp);

        int pick = 0;
        if (wt[ind] <= W)
        {
            pick = val[ind] + solve(ind + 1, W - wt[ind], val, wt, dp);
        }
        return dp[ind][W] = std::max(pick, not_pick);
    }
    int knapsack(int W, std::vector<int> &val, std::vector<int> &wt)
    {
        int n = val.size();
        std::vector<std::vector<int>> dp(val.size() + 1, std::vector<int>(W + 1, -1));
        int ans = solve(0, W, val, wt, dp);
        // cout<<dp[0][W]<<"\n";
        return ans;
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