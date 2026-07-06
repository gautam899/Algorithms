#include <vector>
#include <iostream>
#include <limits.h>
/*
    The input array contains negative which makes it different from the Maximum subarray sum in which
    we use kadane's algorithm. In here negative elements change everything. The problem occurs when there
    are odd number of negatives. To make the number of negative's even we have to remove one negative. Since the
    subarray must be contigious we can either remove the first negative from the starting or the last negative from the
    ending.
    1. Either the whole segment is the best
    2. Excluding the segment upto the first negative(inclusive)
    3. Excluding the segment from the last negative(inclusive) to the end.
*/
class Solution
{
public:
    int maxProduct(std::vector<int> &nums)
    {
        int res = nums[0];
        int n = nums.size();
        int prefix = 0, suffix = 0;

        for (int i = 0; i < n; i++)
        {
            prefix = (prefix ? prefix : 1) * nums[i];
            suffix = (suffix ? suffix : 1) * nums[n - i - 1];

            res = std::max(res, std::max(prefix, suffix));
        }
        return res;
    }
};
int main()
{
    std::vector<int> nums = {1, 2, 3, 0, -4, -5};
    Solution sol;
    int ans = sol.maxProduct(nums);
    std::cout << "Max subarray product is: " << ans << std::endl;
    return 0;
}