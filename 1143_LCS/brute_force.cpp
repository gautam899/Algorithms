#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        // Solution Inspired from.
        // https://en.wikipedia.org/wiki/Longest_common_subsequence
        /* Brute force approach. */
        int m = text1.size(), n = text2.size();
        std::vector<std::vector<int>> v(m+1, std::vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1] == text2[j-1]){
                    v[i][j] = (1 + v[i-1][j-1]);
                } else {
                    v[i][j] = std::max(v[i-1][j], v[i][j-1]);
                }
            }
        }
        return v[m][n];
    }
};

int main() {
    std::string text1 = "abc";
    std::string text2 = "abc";
    Solution sol;
    int ans = sol.longestCommonSubsequence(text1, text2);
    std::cout<<ans<<std::endl;
    return 0;

}