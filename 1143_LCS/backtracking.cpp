#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

class Solution {
public:
    int helper(std::string& s1, std::string& s2, std::vector<std::vector<int>>& dp, int i, int j){
        if(i==0 || j == 0){
            return 0;
        }

        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = 1 + helper(s1, s2, dp, i-1, j-1);
        } else if(dp[i][j-1] > dp[i-1][j]){
            return dp[i][j] = helper(s1, s2, dp, i-1, j);
        }

        return dp[i][j] = helper(s1, s2, dp, i, j-1);
    }
    int longestCommonSubsequence(std::string text1, std::string text2) {
        // Solution Inspired from.
        // https://en.wikipedia.org/wiki/Longest_common_subsequence
        /* Dynamic Programming approach */
        int m = text1.size();
        int n = text2.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));
        int ans = helper(text1, text2, dp, m, n);
        return ans;
    }
};

int main() {
    std::string text1 = "abc";
    std::string text2 = "def";
    Solution sol;
    int ans = sol.longestCommonSubsequence(text1, text2);
    std::cout<<ans<<std::endl;
    return 0;
}