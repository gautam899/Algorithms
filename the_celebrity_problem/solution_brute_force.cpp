#include<iostream>
#include<vector>

class Solution {
  public:
    int celebrity(std::vector<vector<int>>& mat) {
        // code here
        // Brute force
        int n = mat.size();
        vector<int> is_celeb(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && mat[i][j] == 1){
                    is_celeb[i] = 1;
                    break; // i knows someone, we do not want to check for further j.
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if (is_celeb[i] == 0){
                // At this moment we can say i could be a celeb. But no, 
                // being a celeb also requires to be known by everyone. 
                // i knows no-one but is it knows by everyone.
                // We check the column i
                for(int r = 0;r<n;r++){
                    if(mat[r][i] == 0){
                        // r does not know i. i cannot be a cel.
                        is_celeb[i] = 1;
                        break;
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(is_celeb[i] == 0)return i;
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
