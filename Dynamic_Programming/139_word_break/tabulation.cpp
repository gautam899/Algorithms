#include <limits.h>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
    int MAX_LEN = INT_MIN;

    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        int n = wordDict.size();
        for (int i = 0; i < n; i++)
        {
            MAX_LEN = std::max(MAX_LEN, (int)wordDict[i].size());
        }
        std::vector<int> dp(s.size() + 1, 0);
        std::unordered_set<std::string> st(wordDict.begin(), wordDict.end());
        dp[s.size()] = 1; // Base case
        for (int idx = s.size() - 1; idx >= 0; idx--)
        {
            for (int i = idx; i < s.size() && (i - idx + 1) <= MAX_LEN; i++)
            {
                if (st.find(s.substr(idx, i - idx + 1)) != st.end())
                {
                    if (dp[i + 1] == 1)
                    {
                        dp[idx] = 1;
                    }
                }
            }
        }
        return dp[0];
    }
};

int main()
{
    Solution sol;
    std::string s = "leetcode";
    std::vector<std::string> wordDict = {"leet", "code"};
    bool ans = sol.wordBreak(s, wordDict);
    std::cout << ans << std::endl;
    return 0;
}