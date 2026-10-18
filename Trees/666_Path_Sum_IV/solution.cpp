#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int total = 0;
    void dfs(int key, int sum, std::unordered_map<int, int> &mp)
    {
        if (mp.find(key) == mp.end()) // If the key does not exist
            return;

        sum += mp[key];

        int d = key / 10;
        int p = key % 10;
        // Left child: Depth is d+1 and position is 2*p-1
        // Right child: Depth is d+1 and position is 2*p
        int left_key = (d + 1) * 10 + 2 * p - 1;
        int right_key = (d + 1) * 10 + 2 * p;

        if (mp.find(left_key) == mp.end() && mp.find(right_key) == mp.end())
        {
            // If it's a leaf node.
            total += sum;
            return;
        }
        dfs(left_key, sum, mp);
        dfs(right_key, sum, mp);
    }

    int pathSumIV(std::vector<int> &nums)
    {
        std::unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int key = num / 10;
            int val = num - (key * 10);
            mp[key] = val;
        }

        int key = nums[0] / 10;
        dfs(key, 0, mp);
        return total;
    }
};

int main()
{
    std::vector<int> nums = {113, 221, 334, 342};
    Solution sol;
    int ans = sol.pathSumIV(nums);
    std::cout << ans << std::endl;
    return 0;
}