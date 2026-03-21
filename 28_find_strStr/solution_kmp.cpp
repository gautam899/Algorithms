#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int n = haystack.size(), m = needle.size();
        if(n < m){
            return -1;
        }
        // Create the LPS array
	std::vector<int> lps(m,0);
        int prevLPS = 0, i = 1;
        while(i<m){
            if(needle[i] == needle[prevLPS]){
                // We can increase the lenght of LPS.
                lps[i] = ++prevLPS; i++;
            } else {
                // If a mismatch
                if(prevLPS == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    prevLPS = lps[prevLPS - 1];
                }
            }
        }

        // The KMP part of the algorithm
        i=0;
        int j=0; // i for the haystack, j for the needle
        while(i<n){
            if(haystack[i] == needle[j]){
                i++;j++;
                if(j == m){
                    return (i-j);
                }
            } else {
                if( j == 0){
                    // If the mismatch happened with the first character itself
                    i++;
                } else {
                    j = lps[j-1];
                }
            } 
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::string s1 = "aaacaaax";
    std::string s2 = "aaax";
    int ans = sol.strStr(s1, s2);
    std::cout<<ans;
    return 0;
}
