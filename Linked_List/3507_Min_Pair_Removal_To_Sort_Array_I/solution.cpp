#include <vector>
#include <algorithm>

class Solution
{
public:
    int findPos(const std::vector<int> &nums)
    {
        int pos = -1;
        int minSum = 1e9;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] + nums[i + 1] < minSum)
            {
                minSum = nums[i] + nums[i + 1];
                pos = i;
            }
        }
        return pos;
    }
    void mergePairs(std::vector<int> &nums)
    {
        int pos = findPos(nums);
        nums[pos] += nums[pos + 1];
        nums.erase(nums.begin() + pos + 1);
        return;
    }

    int minimumPairRemoval(std::vector<int> &nums)
    {
        // The approach is to simply simulate the process. T.C: O(N)
        int ans = 0;
        while (!std::is_sorted(nums.begin(), nums.end()))
        {
            mergePairs(nums);
            ans++;
        }
        return ans;
    }
};