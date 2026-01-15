class Solution {
  public:
    void helper(int r, int c, vector<vector<int>> &maze, vector<vector<int>> &vis, string curr, vector<string> &ans, int n){
        // base case 
        if(r == n-1 && c == n-1){
            ans.push_back(curr);
            return;
        }
        vis[r][c] = 1;
        // U D L R
        int delr[] = {1, 0, 0, -1};
        int delc[] = {0, -1, 1, 0};
        vector<char> dir = {'D', 'L', 'R', 'U'}; // Directions must be in lexicographical order.
        
        for(int i=0;i<4;i++){
            int nr = r+delr[i];
            int nc = c+delc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<n && maze[nr][nc]==1 && vis[nr][nc] == 0){
                
                helper(nr, nc, maze, vis, curr + dir[i], ans, n);
            }
        }
        // Checked all direction but nowhere to go. Backtrack.
        vis[r][c] = 0;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        int n = maze.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        helper(0,0, maze, vis, "", ans, n);
        return ans;
    }
};
