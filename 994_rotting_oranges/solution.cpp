class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // kind of a level order traversal using queue.
        queue<pair<int,int>> q;
        int rows = grid.size(), cols = grid[0].size();
        int time = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            // Iterate the current level and for every member visit the neighbour.
            for(int i=0;i<size;i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    // perform some checks
                    int nr = dr[j] + r;
                    int nc = dc[j] + c;
                    // 1. Must be inside boundaries 2. Must be fresh and not (rotten or empty)
                    if(nr < rows && nr >= 0 && nc < cols && nc >=0 && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr,nc});             
                    }
                }
            }
            // Only increment time if some rotting happened on this level. If we increment the time even if no rotting happens, then we will overshoot the time by one.
            (!q.empty()) ? time++ : 0;
        }
        // If still fresh orange left return -1
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};
