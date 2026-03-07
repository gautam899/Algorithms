class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // Another approach is two pointer approach.
        // Start with two pointer: one at the start and the other at the end.
        // Check if a knows b, if yes, a cannot be a celeb and inc a, same for
        // b just decrement.
        // At the end check for possible celeb, that if it is even a celeb.
        
        int n = mat.size();
        int i=0,j=n-1;
        while(i<j){
            if(mat[i][j] == 1){
                i++;
            } else {
                j--;
            }
        }
        int c = i;
        for(int i=0;i<n;i++){
            if(c!=i && (mat[c][i] == 1 || mat[i][c] == 0)) return -1;
        }
        return c;
    }
};
