#include <limits.h>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        std::vector<int> dp(s.size() + 1, 0);
        dp[0] = true;
        // dp[i]? Whether substring from 0 to i can be segmented from the words in the dict.
        for (int i = 1; i <= s.size(); i++) // O(s.size()) => O(N)
        {
            for (const auto &w : wordDict) // O(M)
            {
                int start = i - w.size();
                // Start must be greater than zero and substring from index 0->start must be segmentable and substring starting from index start with length of w must be equal to w
                if (start >= 0 && dp[start] == true && s.substr(start, w.size()) == w)
                {
                    dp[i] = true; // substr from 0->i can be segmented
                    break;
                }
            }
        }
        return dp[s.size()];
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