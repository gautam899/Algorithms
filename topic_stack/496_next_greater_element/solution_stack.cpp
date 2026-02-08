class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Let's take an example
        /* nums1 = [2,3,4];
          nums2 = [3,2,4,6];
        * Since nums1 is a subset of nums2we iterate only nums2 and store the next greater of every elmenent in a map. 
        *And then check with nums1. In the above example it's clear that 2 maps with 4 and 4 maps with 6.
        * But what about 3, we do not see a immediate next greater, which implies that we need to hold 
        * on to 3 until we see a greater element and only process it then.
        * But how? There could be more element who do not have immediate next greater element.
        * Stack? Keep elements for whome we haven't found the next greater element yet.
        * If the current element is greater than the top of the stack it is the next greater for the
        * stack top or more in the stack.
        * Every time we find a next greater we push the {key,value} pair in the map and once we are 
        * done iterating nums2 we start with nums1 and check the mapped values.
        */
        unordered_map<int,int> mp;
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && nums2[i] > st.top()){
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i]) == mp.end()){
                ans.push_back(-1);
            } else{
                ans.push_back(mp[nums1[i]]);
            }
        }
        return ans;

    }
};
