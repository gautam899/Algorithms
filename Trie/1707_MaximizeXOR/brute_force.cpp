#include <vector>

class Solution
{
public:
    std::vector<int> maximizeXor(std::vector<int> &nums, std::vector<std::vector<int>> &queries)
    {
        // Brute force approach:
        int n1 = nums.size();
        int n2 = queries.size();
        std::vector<int> v;
        for (const auto &it : queries)
        {
            int x = it[0];
            int m = it[1];
            int ans = -1;
            for (int i = 0; i < n1; i++)
            {
                if (nums[i] <= m)
                {
                    ans = std::max(ans, x ^ nums[i]);
                }
            }
            v.push_back(ans);
        }
        return v;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = {0, 1, 2, 3, 4};
    std::vector<std::vector<int>> queries = {{3, 1},
                                             {1, 3},
                                             {5, 6}};
    std::vector<int> ans = sol.maximizeXor(nums, queries);
    return 0;
}