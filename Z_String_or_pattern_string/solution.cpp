#include<iostream>
#include<vector>
#include<string>

class Solution {
  public:
    std::vector<int> search(std::string &pat, std::string &txt) {
        // code here
        // KMP algorithm
        int n = pat.size(), m = txt.size();
        if(m<n) return {};
	std::vector<int> lps(n,0);
        int i = 1, prevLPS = 0;
        while(i<n){
            if(pat[i] == pat[prevLPS]){
                lps[i++] = ++prevLPS;
            } else {
                if(prevLPS == 0){
                    lps[i] = 0;
                    i++;
                } else {
                    prevLPS = lps[prevLPS - 1];
                }
            }
        }
        
	std::vector<int> ans;
        i=0; // for txt
        int j = 0; // for pat
        while(i<m){
            if(pat[j] == txt[i]){
                i++;
                j++;
                // cout<<i<<" "<<j<<endl;
                if(j == n){
                    // cout<<j<<endl;
                    ans.push_back(i-j);
                    j=lps[j-1]; // How may characters can we avoid matching again.
                }
            } else {
                // If the mismatch happened at 0th index
                if(j==0){
                    i++;
                } else {
                    j = lps[j-1];
                }
            }
        }
        return ans;
    }
};

int main(){
    std::vector<int> ans;
    Solution sol;
    std::string pat = "ll";
    std::string text = "hello";
    ans = sol.search(pat, text);
    for(int i =0;i<ans.size();i++){
       std::cout<<ans[i];
    }
    return 0;
}
