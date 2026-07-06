#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int lengthOfLIS(std::vector<int> &nums)
    {
        std::vector<int> LIS(nums.size(), 1); // Starting at any index the longest increasing
        // subsequence will be atleast a length 1, hence we initialize the dp to 1 for every index

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] < nums[j])
                {
                    LIS[i] = std::max(LIS[i], 1 + LIS[j]);
                }
            }
        }
        return *max_element(LIS.begin(), LIS.end()); // Maximum LIS can be achived from any index, hence the max needs to be taken.
    }
};

int main()
{
    std::vector<int> nums = {1, 2, 4, 3};
    Solution sol;
    int ans = sol.lengthOfLIS(nums);
    std::cout << ans << std::endl;
    return 0;
    // For every index we check all the index that come after it. Therefore, time complexity is
    // O(N^2).
}
