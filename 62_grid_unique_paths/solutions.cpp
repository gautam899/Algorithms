#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    int find_path(int r,int c, int m, int n, vector<vector<int>> &vis){
        // If we are at the destination.
        if(r == m-1 && c == n-1){
            return 1;
        }
        vis[r][c] = 1; // Visit the current indices
        int delr[] = { 0, 1};
        int delc[] = {1, 0};
        int res = 0;
        // We have 2 directions to go. Down and right.
        for(int i=0;i<2;i++){
            int nr = r + delr[i];
            int nc = c + delc[i];
            // If not out of bounds and not visited already.
            if(nr>=0 && nr<m && nc >=0 && nc<n && vis[nr][nc]==0){
                res += find_path(nr,nc,m,n,vis);
            }
        }
        vis[r][c]=0; // backtrack.
        return res;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> vis(m, vector<int>(n,0));
        int ans = find_path(0,0,m,n,vis);
        return ans;
        // The above solution is a bit too much. Since we can only move down and right there is no cycle possible and hence we do not need to visited array.
    }
    */
    int find_path(int r,int c, int m, int n, vector<vector<int>> &dp){
        // If we are at the destination.
        if(r == m-1 && c == n-1){
            return 1;
        }
        // Out of bounds.
        if(r>=m || c >=n){
            return 0;
        }
        if(dp[r][c] != -1) return dp[r][c];
        return dp[r][c] = find_path(r+1, c, m, n, dp) + find_path(r, c+1, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = find_path(0,0,m,n, dp);
        return ans;
    }
};

int main() {
    Solution sol;
    int m = 3,n = 7;
    int ans = sol.uniquePaths(m, n);
    cout<<ans;
    return 0; 
}
