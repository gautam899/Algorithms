class Solution {
public:
    void helper(vector<int> nums, vector<int> &curr, vector<vector<int>> &ans, vector<int> &vis){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }

        for(int i=0;i<nums.size();i++){
            // If already included
            if(vis[i] == 0){
                continue;
            }
            curr.push_back(nums[i]);
            vis[i] = 0; // mark visited
            helper(nums, curr, ans, vis);
            curr.pop_back();
            vis[i] = -1; // backtrack
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> vis(nums.size(), -1);
        helper(nums, curr, ans, vis);
        return ans;
    }
};
