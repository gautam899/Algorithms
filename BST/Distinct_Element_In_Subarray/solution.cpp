#include <iostream>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<int> __distinct_element_in_subarray(std::vector<int> &v, std::unordered_map<int, int> &mp, int k)
    {
        std::vector<int> ans;
        // Put the entries for the first k elements in the map
        for (int i = 0; i < k; i++)
        {
            mp[v[i]]++;
        }

        ans.push_back(mp.size());

        for (int i = k; i < v.size(); i++)
        {
            // Increase the count for the element coming in the sliding window.
            mp[v[i]]++;

            if (--mp[v[i - k]] == 0)
            {
                mp.erase(v[i - k]);
            }

            ans.push_back(mp.size());
        }
        return ans;
    }
};

int main()
{
    std::vector<int> v = {1, 2, 1, 3, 4};
    Solution sol;
    std::unordered_map<int, int> mp;
    std::vector<int> ans = sol.__distinct_element_in_subarray(v, mp, 3);
    for (auto it : ans)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    return 0;
}