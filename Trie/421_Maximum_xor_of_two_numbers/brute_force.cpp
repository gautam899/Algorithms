#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    int findMaximumXOR(std::vector<int> &nums)
    {
        // Brute Force operation
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (i != j)
                {
                    ans = std::max(ans, nums[i] ^ nums[j]);
                }
            }
        }
        return ans;
        // T.C O(N^2).
    }
};

int main()
{
    std::vector<int> nums = {3, 10, 5, 25, 2, 8};
    Solution sol;
    int ans = sol.findMaximumXOR(nums);
    std::cout << ans << std::endl;
    return 0;
}