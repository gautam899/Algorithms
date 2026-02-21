class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<nums.size();i++){
            // Check for out of bound element. i.e if the front index is outside the current window
            if(!dq.empty() && dq.front() == i-k) dq.pop_front();
            // When we move to the next windows we do not want to keep the smaller elements than the current element.
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
