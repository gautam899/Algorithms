#include <iostream>
#include <vector>
#include <limits.h>

class Solution
{
public:
    int maxProduct(std::vector<int> &nums)
    {
        int res = nums[0];
        int maxp = nums[0];
        int minp = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int curr = nums[i];
            /*
                Swap because a negative can turn a max in min and min into max.
                Let's say out min in -ve, if the curr is negative we would want to make the minp our maxp so that when we multiply the -ve with the curr we get a positive max.
            */
            if (curr < 0)
                std::swap(maxp, minp);
            maxp = std::max(curr, maxp * curr);
            minp = std::min(curr, minp * curr);
            res = std::max(res, maxp);
        }
        return res;
    }
};

int main()
{
    std::vector<int> nums = {1, 2, -3, 0, -4, -5};
    Solution sol;
    int ans = sol.maxProduct(nums);
    std::cout << "Maximum Subarray Product is: " << ans << std::endl;
    // Time complexity: O(N).
    return 0;
}