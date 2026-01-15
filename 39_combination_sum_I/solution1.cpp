#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	void helper(int idx, vector<int> nums, vector<vector<int>> &ans){
		if(idx == nums.size()){
			ans.push_back(nums);
			return;
		}
		for(int index = idx;index < nums.size(); index++){
			swap(nums[idx], nums[index]);
			helper(idx+1, nums, ans);
			swap(nums[idx], nums[index]); // backtrack
		
		}
	}
	vector<vector<int>> find_permutation(vector<int> &nums){
		int n = nums.size();
		vector<vector<int>> ans;
		helper(0, nums, ans);
		return ans;
	}
};

int main() {
	vector<int> arr = {1,2,3};
	Solution sol;
	vector<vector<int>> ans = sol.find_permutation(arr);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[0].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

