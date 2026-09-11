#include <vector>
#include <algorithm>

class Solution
{
public:
    int helper(int ind, std::vector<int> &nums, int canPick, std::vector<std::vector<int>> &dp)
    {
        if (ind == nums.size())
            return 0;

        if (dp[ind][canPick] != -1)
            return dp[ind][canPick];
        int pick = 0;
        // If we are allowed to pick this node.
        if (canPick == 1)
        {
            pick = nums[ind] + helper(ind + 1, nums, 0, dp);
        }

        int notPick = helper(ind + 1, nums, 1, dp);

        return dp[ind][canPick] = std::max(pick, notPick);
    }
    int rob(std::vector<int> &nums)
    {
        /* For every index, we have two possiblities.
            With a index, what is max amount that can be sto
        */

        std::vector<std::vector<int>> dp(nums.size() + 1, std::vector<int>(2, -1));
        return helper(0, nums, 1, dp);
    }
};