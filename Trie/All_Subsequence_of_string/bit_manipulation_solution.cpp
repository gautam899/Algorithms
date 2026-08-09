#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
    The problem at hand is to take a string and generate all possible subsequence include the string and and empty string.
    To solve this problem we can use the concept of power set. If n is the length of the string, we generate all numbers in binary from
    0->n and for every number we can check for all the set bits. The character corresponding to the index of the set bit will be included
    in the subsequence.
*/
class Solution
{
public:
    std::vector<std::string> allStringSubsequence(const std::string &s)
    {
        std::vector<std::string> ans;
        int n = s.size();
        for (int i = 0; i < (1 << n); i++) // O(2^n)
        {
            ans.emplace_back(); // One string per subset
            std::string sub = "";
            for (int j = 0; j < n; j++) // O(n)
            {
                if (i & (1 << j))
                    ans.back() += s[j];
            }
        }
        return ans;
        // Total time complexity O()
    }
};

int main()
{
    std::string s = "abc";
    Solution sol;
    std::vector<std::string> ans = sol.allStringSubsequence(s);
    std::sort(ans.begin(), ans.end());
    for (const std::string &it : ans)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    return 0;
}