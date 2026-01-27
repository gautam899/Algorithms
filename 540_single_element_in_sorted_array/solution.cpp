class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        /*
        int n = nums.size();
        if(n == 1)return nums[0];
        int ans;
        int i=0;
        while(i<n){
            if(nums[i] == nums[i+1]){
                i++;
            } else {
                ans = nums[i];
                break;
            }
            i++;
        }
        return ans;
        */
        // Time complexity is O(N).

        // Binary search.
        // 1. For pairs before the single element all the first occurence happens to be at even index. 
        // 2. After the single element occurrence, the first occurence of each pairs happens at odd index.
        int l = 0, r = nums.size()-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(mid % 2 == 1){
                mid--;
            }

            if(nums[mid] == nums[mid+1]){
                // on the right
                l = mid+2;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};
