class Solution {
public:
    bool checkPalindrome(vector<string>& curr) {
            int flag = 1;
            for (int i = 0; i < curr.size(); i++) {
                string s = curr[i];
                int l = 0, r = s.size() - 1;
                while (l <= r) {
                    if (s[l] != s[r]) {
                        flag = 0;
                        break;
                    }
                    l++;
                    r--;
                }
                if (flag == 0)
                    return false; // No need to continue.
            }
            return true; // If all goes well.
    }
        
    void helper(int idx, string s, vector<string>& curr,
                vector<vector<string>>& ans) {

         if (idx == s.size()) {
             if (checkPalindrome(curr) == true) {
                 ans.push_back(curr);
             } else {
                 return;
             }
         }

        for (int i = idx; i < s.size(); i++) {
            curr.push_back(s.substr(idx, i - idx + 1));
            helper(i + 1, s, curr, ans);
            curr.pop_back(); // backtrack.
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> curr;
        helper(0, s, curr, ans);
        return ans;
    }
};
