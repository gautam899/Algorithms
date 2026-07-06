#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int solve(int idx, int prev, std::vector<int> &nums, std::vector<std::vector<int>> &dp)
    {
        if (idx == nums.size())
        {
            return 0;
        }
        // Why prev+1 because prev starts from -1 and we cannot have a -ve index in the dp, hence we start from prev+1.
        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1]; // If we already know the longest increasing subsequence till idx, there is no need to redo
        int length = 0 + solve(idx + 1, prev, nums, dp);

        if (prev == -1 || nums[idx] > nums[prev])
        {
            length = std::max(length, 1 + solve(idx + 1, idx, nums, dp));
        }
        return dp[idx][prev + 1] = length;
    }
    int lengthOfLIS(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> dp(nums.size() + 1, std::vector<int>(nums.size() + 2, -1));
        return solve(0, -1, nums, dp);
    }
};

int main()
{
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution sol;
    int ans = sol.lengthOfLIS(nums);
    std::cout << ans << std::endl;
    return 0;
}
