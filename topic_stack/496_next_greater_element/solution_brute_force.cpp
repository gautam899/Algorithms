class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n1 = nums1.size(),n2 = nums2.size();
        for(int i=0;i<n1;i++){
            int num = nums1[i];
            for(int j=0;j<n2; j++){
                if(nums2[j] == num){
                    if(j == n2-1){
                        ans.push_back(-1);
                    } else{
                        int f = 0;
                        for(int k=j+1;k<n2;k++){
                            if(nums2[k] > num){
                                ans.push_back(nums2[k]);
                                f = 1;
                                break;
                            }
                        }
                        if(f==0){
                            ans.push_back(-1);
                        }

                    }
                }
            }
        }
        return ans;
    }
};
