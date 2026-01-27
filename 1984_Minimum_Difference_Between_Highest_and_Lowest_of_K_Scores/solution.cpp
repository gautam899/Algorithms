#include<vector>
#include<climits>
#include<iostream>
#include<algorithm>

class Solution {
public:
    int minimumDifference(std::vector<int>& nums, int k) {
	    std::sort(nums.begin(), nums.end());
        // for(auto &it:nums){
        //     cout<<it<<" ";
        // }
        if(k==1)return 0;
        int n = nums.size();
        int l=0, r = k-1;
        int ans = INT_MAX;
        while(r<n){
            ans = std::min(ans, nums[r++]-nums[l++]);
        }
        return ans;
    }
};
int main(){
	std::vector<int> nums = {4,1,9,7};
	Solution sol;
	int ans = sol.minimumDifference(nums,2);
	std::cout<<ans;
	return 0;
}
