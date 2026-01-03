#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
		return 0;
	}
	unordered_map<char, int> mp;
	int ans = INT_MIN;
	int l=0,r=0;// sliding window.
        while(r<s.size()){
		mp[s[r]]++;
		// Check if all char occur once.
		if(r-l+1 == mp.size()){
			ans = max(ans, r-l+1);
		}

		// If current window has repeated char. shrink until no more repetition.
		while(r-l+1>mp.size()){
			mp[s[l]]--;
			// if the entry value becomes zero, remove
			if(mp[s[l]] == 0){
				mp.erase(s[l]);
			}
			l++;
		}
		r++;
	}
	return ans;
    }
};

int main() {
	// 
    string s = "aaaaa";
    Solution sol;
    int ans = sol.lengthOfLongestSubstring(s);
    cout<<ans;
}
