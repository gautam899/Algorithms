class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Brute force approach is to merge the two arrays into one and find the median.
        // A better approach could be to use merge sort to merge the arrays and then finding the median.
        vector<int> merged;
        int n=nums1.size(),m=nums2.size();
        int l=0, r=0;
        while(l<n && r<m){
            if(nums1[l] <= nums2[r]){
                merged.push_back(nums1[l++]);
            } else {
                merged.push_back(nums2[r++]);
            }
        }
        while(l < n){
            merged.push_back(nums1[l++]);
        }
        while(r < m){
            merged.push_back(nums2[r++]);
        }
        int k = merged.size()/2;
        // for(auto &it:merged){
        //     cout<<it;
        // }
        // cout<<k;
        // double ans;
        if(merged.size() % 2 == 1){
            return merged[k];
        } else {
            return (merged[k] + merged[k-1])/2.0;
        }
        // return ans;
    }
};
