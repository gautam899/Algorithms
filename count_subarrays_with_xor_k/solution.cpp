#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        // Brute force is loop through all the possible subarray and find the count.
        // Time complexity will be at be O(N^2) with two loops.
        // Optimal approach: Think of the problem "count subarray sum k".
        // We used the approach of prefix sum: p[l] = p[r] - k. 
        // Same we can do here preXOR[l-1] = preXOR[r] ^ k. We need to ask
        // check how many time we have already seen a xor value of 
        // currXOR^k. That is the number of times a subarray with xor k has occured.
        
        int n = arr.size();
        if(n == 0){
            return 0;
        }
        unordered_map<int,int> mp;
        mp[0] = 1;
        int curr_xor = 0;
        long long ans = 0;
        for(int i=0;i<n;i++){
            curr_xor ^= arr[i];
            int xor_to_check = curr_xor^k;
            // Check if curr_xor^k has occurred before.
            if(mp.find(xor_to_check) != mp.end()){
                ans += mp[xor_to_check];
            }
            mp[curr_xor]++;
        }
        return ans;
    }
};

int main() {
	/*
    vector<vector<int>> test_cases = {{},{},{}};
    Solution sol;
    for(const auto &v: test_case){
    	int ans = sol.
    }
    */
    vector<int> arr = {1,1,1,1};
    int k = 0;
    Solution sol;
    long long ans = sol.subarrayXor(arr, k);
    cout<<ans;
}
