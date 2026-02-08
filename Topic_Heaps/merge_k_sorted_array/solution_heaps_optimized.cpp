class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        // Brute force approach is to put all the elements in a vector and sort
        // them. TC->O(N + NLogN)
        
        // Let's try with Heap(minH).
        vector<int> ans;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> minH;
        int k = mat.size();
        for(int i=0;i<k;i++){
            minH.push({mat[i][0], {i,0}});
        }
        // We start with the minimum element and then push the next element in
        // the same array into the heap. This way we always get minimum element first.
        while(!minH.empty()){
            int num = minH.top().first;
            int i = minH.top().second.first;
            int j = minH.top().second.second;
            minH.pop();
            ans.push_back(num);
            if(j+1 < mat[0].size()){
                minH.push({mat[i][j+1],{i,j+1}});
            }
        }
        return ans;
        
    }
};
