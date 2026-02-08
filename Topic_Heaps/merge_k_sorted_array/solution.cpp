class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        // Brute force approach is to put all the elements in a vector and sort
        // them. TC->O(N + NLogN)
        
        // Let's try with Heap(minH).
        priority_queue<int, vector<int>, greater<int>> minH;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                minH.push(mat[i][j]);
            }
        }
        vector<int> ans;
        while(!minH.empty()){
            ans.push_back(minH.top());
            minH.pop();
        }
        return ans;
    }
};
