class Solution {
  public:
    static constexpr int dr[4] = {1, 0, 0, -1};
    static constexpr int dc[4] = {0, -1, 1, 0};
    static constexpr char dir[4] = {'D', 'L', 'R', 'U'};
    void helper(int r, int c, vector<vector<int>> &maze, vector<vector<int>> &vis, 
    string &path, vector<string> &ans, int n){
        // base case 
        if(r == n-1 && c == n-1){
            ans.push_back(path);
            return;
        }
        vis[r][c] = 1;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<n && maze[nr][nc]==1 && vis[nr][nc] == 0){
                path.push_back(dir[i]);
                helper(nr, nc, maze, vis, path, ans, n);
                path.pop_back();
            }
        }
        // Checked all direction but nowhere to go. Backtrack.
        vis[r][c] = 0;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        int n = maze.size();
        string path;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        helper(0,0, maze, vis, path, ans, n);
        return ans;
    }
};
