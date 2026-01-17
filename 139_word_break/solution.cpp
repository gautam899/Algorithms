#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(int idx, string& s, unordered_set<string>& st,
                vector<int>& dp) {
        if (idx == s.size())
            return true;
        if (dp[idx] != -1)
            return dp[idx];
        string curr = "";
        for (int i = idx; i < s.size(); i++) {
            curr += s[i];
            if (st.find(curr) != st.end()) {
                cout << curr << " ";
                if (helper(i + 1, s, st, dp))
                    return true;
            }
        }
        return dp[idx] = false; // went through a possible string from idx till end but
                      // did not found any that is in the dictionary.
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n, -1);
        return helper(0, s, st, dp);
    }
};

int main() {
    
}
