#include<iostream>
#include<string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int n = haystack.size(), m = needle.size();
        if(n < m)return -1;
        for(int i=0;i<n;i++){
            if(needle[0] == haystack[i]){
                int k = i;
                int j = 0;
                while(k<n && j<m && needle[j] == haystack[k]){
                    j++;k++;
                }
                if((k-i) == m) return i;
            }
        }
        return -1;
    }
};

int main() {
    std::string haystack = "aaacaaax";
    std::string needle = "aaax";
    Solution sol;
    int ans = sol.strStr(haystack,needle);
    std::cout<<ans;
    return 0;
}


