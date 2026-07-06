#include <vector>
#include <algorithm>
#include <limits.h>
class Solution
{
public:
    int solve(int ind, std::vector<int> &arr, int prev, std::vector<std::vector<int>> &dp)
    {
        if (ind == arr.size())
            return 0;

        if (dp[ind][prev + 1] != -1)
        {
            return dp[ind][prev + 1];
        }
        int not_pick = 0 + solve(ind + 1, arr, prev, dp);

        int pick = INT_MIN;
        if (prev == -1 || arr[ind] > arr[prev])
        {
            pick = arr[ind] + solve(ind + 1, arr, ind, dp);
        }

        return dp[ind][prev + 1] = std::max(pick, not_pick);
    }
    int maxSumIS(std::vector<int> &arr)
    {
        // code here
        std::vector<std::vector<int>> dp(arr.size(), std::vector<int>(arr.size() + 1, -1));
        return solve(0, arr, -1, dp);
    }
};

int main()
{
}