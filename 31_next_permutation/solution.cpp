#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        int n = nums.size();
	if(n==1)return nums;
	// Find the pivot. Pivot is what we are calling where the increasing suffix breaks.
	int k = -1;
	for(int i=n-2;i>=0;i--){
	   if(nums[i] <= nums[i+1]){
	   	k = i;
		break;
	   }
	}
	if(k == -1){
	    // No pivot found and that implies the array sorted in non-increasing order and hence the next permutation will be the array reversed in itself
	    reverse(nums.begin(), nums.end());
	    return nums;
	}

	// Now we need to find the smallest element greater than the pivot element.
	for(int i=n-1;i>=k;i--){
	    if(nums[i] > nums[k]){
	    	swap(nums[i], nums[k]);
		reverse(nums.begin() + k + 1, nums.end());
		break;
	    }
	}
	return nums;
    }
};

int main() {
   vector<int> arr = {3,2,1};
   Solution sol;
   vector<int> ans = sol.nextPermutation(arr);
   for(int i=0;i<ans.size();i++){
   	cout<<ans[i];
   }
   cout<<"\n";
   return 0;
}
