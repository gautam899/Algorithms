#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Brute force approach is to sort the array and process. 
        int n = nums.size();
        if(n==0)return 0;
        sort(nums.begin(),nums.end());
        int maxi=1;
        int curr_len = 1;
        for(int i=1;i<n;i++){
            if(nums[i] == (nums[i-1]+1)) {
                curr_len++;
            } else if (nums[i] != nums[i-1]){
                // We will only reset the count to one if curr is not equal to the prev. Conside this ex: [0,1,1,2]. We start at index 1 count = 2, index 3 we see nums[3] != nums[2]+1 but it is equal. Hence we do not increment the count but also not reset it because the next could be 1+1.
                curr_len = 1;
            }
            maxi = max(maxi, curr_len);
        }
        return maxi;
    }
};

int main() {
    vector<int> nums = {1,0,1,2};
    Solution sol;
    int ans = sol.longestConsecutive(nums);
    cout<<ans;
    return ans;
}
