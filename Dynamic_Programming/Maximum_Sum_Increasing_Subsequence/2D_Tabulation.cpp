#include <vector>
#include <algorithm>
#include <limits.h>

/*
    Observe: The pattern in the memoization
    To evaluate ind we depend upon ind+1
    pick = solve(ind+1, ind)
    not_pick = solve(ind+1, prev)
    Which implies we must evaluate the larger index first.
    For index i, the prev can be anywhere from i-1 <- 0.

    So What's dp[i][j] here? With index j as the prev, what is the max increasing subsequence from index
    i -> n.
*/
class Solution
{
public:
    int maxSumIS(std::vector<int> &arr)
    {
        int n = arr.size();
        std::vector<std::vector<int>> dp(arr.size() + 1, std::vector<int>(arr.size() + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev = ind - 1; prev >= -1; prev--)
            {
                int not_pick = 0 + dp[ind + 1][prev + 1];

                int pick = INT_MIN;
                if (prev == -1 || arr[ind] > arr[prev])
                {
                    pick = arr[ind] + dp[ind + 1][ind + 1];
                }

                dp[ind][prev + 1] = std::max(pick, not_pick);
            }
        }
        return dp[0][0];
        // Time Complexity: O(N^2)
        // Space Complexity: O(N^2)
    }
};

int main()
{
}