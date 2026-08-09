#include <iostream>
#include <vector>

class Solution
{
public:
    bool isSubsetSum(std::vector<int> &arr, int sum)
    {
        // code here
        // code here
        std::vector<int> curr(sum + 1, 0);
        std::vector<int> next(sum + 1, 0);
        int n = arr.size();
        // Base case
        curr[0] = 1;
        next[0] = 1;
        // dp[i][j]? Starting from index i with remaining sum j, is there a subset with target sum.
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= sum; j++)
            {
                bool np = next[j];
                bool p = false;
                if (arr[i] <= j)
                {
                    p = next[j - arr[i]];
                }
                curr[j] = p || np;
            }
            next = curr;
        }
        return curr[sum];
    }
};