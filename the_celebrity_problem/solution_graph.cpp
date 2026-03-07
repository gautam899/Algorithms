class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // We can think of this problem as a directed graph as-well. 
        // if i->j i.e. i knows j. The out-degree of i increase by one and in-
        // -degree of j increase by one. If the out-degree of some is 0(knows no-one),
        // for them to be celeb their indegree must be n(known by everyone).
        int n = mat.size();
        vector<int> outdegree(n,0);
        vector<int> indegree(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( i!=j && mat[i][j] == 1){
                    outdegree[i]++;
                    indegree[j]++;
                }
            }
        }
        // for(auto it:outdegree){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it:indegree){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<n;i++){
            // knows no-one execept itself but known by everyone(in degree n-1).
            if(outdegree[i] == 0 && indegree[i] == n-1){
                return i;
            }
        }
        return -1;
        
    }
};

int main(){
    std::vector<vector<int>> mat = {{1,1,1},{0,1,0},{1,0,1}};
    Solution sol;
    int ans = sol.celebrity(mat);
    std::cout<<ans;
    return 0;
}
