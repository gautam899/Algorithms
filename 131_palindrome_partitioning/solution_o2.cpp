class Solution {
public:
    void helper(int idx, string s, vector<string>& curr,
                vector<vector<string>>& ans) {
        // Base case
        if (idx == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            string sub = s.substr(idx, i - idx + 1);
            // check if it's a palindrom here itself
            int l = idx, r = i;
            int flag = 1;
            while (l <= r) {
                if (s[l] != s[r]) {
                    flag = 0;
                    break;
                }
                l++;
                r--;
            }
            if (flag == 0)
                continue; // No use of cutting here as the substring that we are
                          // pushing is not a palindrome in itself
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
