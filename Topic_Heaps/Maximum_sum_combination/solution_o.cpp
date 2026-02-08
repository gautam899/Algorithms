class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        priority_queue<pair<int,pair<int,int>>> maxH; // {Sum,{a[i],b[i]}}
        set<pair<int,int>> st; // Store the visited index.
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>()); // Sort the arrays as we wish to start with
        // the largest sum possible
        int n = a.size();
        int m = b.size();
        vector<int> ans;
        maxH.push({a[0]+b[0], {0, 0}});
        st.insert({0,0});
        while(k>0){
            // Pop the curr max and put it in the result
            ans.push_back(maxH.top().first);
            pair<int,int> index = maxH.top().second;
            maxH.pop(); 
            // Move either of the index by one ahead and find the possible sum
            // Make sure the new indexes are well within the bound and the new pair of indexes is not 
            // visited already.
            if(index.first + 1 < n && st.find({index.first+1,index.second}) == st.end()){
                maxH.push({a[index.first+1]+b[index.second],{index.first+1,index.second}});
                st.insert({index.first+1,index.second}); // Mark the pair of index visited
            }
            
            if(index.second + 1 < n && st.find({index.first,index.second+1}) == st.end()){
                maxH.push({a[index.first]+b[index.second+1],{index.first,index.second+1}});
                st.insert({index.first,index.second+1}); // Mark the pair of index visited
            }
            k--;
        }
        return ans;
    }
};
