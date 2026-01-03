#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int merge(int l, int r, int mid, vector<int> &nums){
        int n1 = mid - l + 1;
        int n2 = r - mid;
        vector<int> v1(n1);
        vector<int> v2(n2);
        for(int i=0;i<n1;i++){
            v1[i] = nums[l+i];
        }
        for(int j=0;j<n2;j++){
            v2[j] = nums[mid+j+1];
        }
        int ans=0;
        // Counting of pairs must be done before sorting.
        int j=0;
        for(int i=0;i<n1;i++){
            while(j<n2 && (long long)v1[i] > (2LL*v2[j])){
                j++;
            }
            ans += j;
        }
        int i=0,k=l;
        j=0;
        while(i<n1 && j<n2){
            if(v1[i] <= v2[j]){
                nums[k++] = v1[i++];
            } else {
                nums[k++] = v2[j++];
            }
        }
        while(i<n1){
            nums[k++] = v1[i++];
        }
        while(j<n2){
            nums[k++] = v2[j++];
        }
        return ans;
    }
    int find_pairs(int l, int r, vector<int> &nums){
        int res = 0;
        if(l<r){
            int mid = (r+l)/2;
            res += find_pairs(l, mid, nums);
            res += find_pairs(mid+1, r, nums);

            res += merge(l, r, mid, nums);
        }
        return res;
    }
    int reversePairs(vector<int>& nums) {
        // We see a pattern here. In the problem inverse pairs in which if i<j, find pairs such that nums[i]>nums[j]. We used merge sort to solve.
        int n = nums.size();
        vector<int> temp = nums;
        int ans = find_pairs(0,n-1,temp);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,2,3,1};
    int ans = sol.reversePairs(nums);
    cout<<ans;
    return 0;
}
