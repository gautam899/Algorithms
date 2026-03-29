#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        // Solution Inspired from.
        // https://en.wikipedia.org/wiki/Longest_common_subsequence
        int m = text1.size(), n = text2.size();
        std::vector<std::vector<int>> v(m+1, std::vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1] == text2[j-1]){
                    /*
                        LCS(X^A,Y^A) = LCS(X,Y)^A, for all strings X, Y and all symbols A, 
                        where ^ denotes string concatenation.
                    */
                    v[i][j] = (1 + v[i-1][j-1]);
                } else {
                    /*
                        If A and B are distinct symbols (A≠B), then LCS(X^A,Y^B) is one of the 
                        maximal-length strings in the set { LCS(X^A,Y), LCS(X,Y^B) },
                        for all strings X, Y.
                    */
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