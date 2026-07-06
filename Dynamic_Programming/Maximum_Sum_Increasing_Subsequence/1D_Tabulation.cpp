#include <vector>
#include <algorithm>
#include <limits.h>

/*
    To convert the 2D tabulation into 1D tabulation, we don't just optimize the 2d to 1d but rather
    change the way of thinking/state. What is the maximum increasing subsequence ending at i.
    To find this we check all the possible prev values and if arr[j] < arr[i], arr[i] could be included
    in the maximum increasing subsequence at j.

*/
class Solution
{
public:
    int maxSumIS(std::vector<int> &arr)
    {
        int n = arr.size();
        std::vector<int> dp = arr;

        int ans = arr[0];
        for (int ind = 1; ind < n; ind++)
        {
            for (int prev = 0; prev < ind; prev++)
            {
                if (arr[prev] < arr[ind])
                {
                    dp[ind] = std::max(dp[ind], arr[ind] + dp[prev]);
                }
            }
            ans = std::max(ans, dp[ind]);
        }
        return ans;
    }
    // Time: O(N^2)
    // Space: O(N)
};

int main()
{
}