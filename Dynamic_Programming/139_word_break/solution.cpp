#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

class Solution
{
public:
    bool helper(int idx, std::string &s, std::unordered_set<std::string> &st,
                std::vector<int> &dp)
    {
        if (idx == s.size())
            return true;
        if (dp[idx] != -1)
            return dp[idx];
        std::string curr = "";
        for (int i = idx; i < s.size(); i++)
        {
            curr += s[i];
            if (st.find(curr) != st.end())
            {
                std::cout << curr << " ";
                if (helper(i + 1, s, st, dp))
                    return true;
            }
        }
        return dp[idx] = false; // went through a possible string from idx till end but
                                // did not found any that is in the dictionary.
    }
    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        std::unordered_set<std::string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        std::vector<int> dp(n, -1);
        return helper(0, s, st, dp);
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