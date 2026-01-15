class Solution {
  public:
    bool isSafe(vector<vector<int>> &adj, int v, vector<int> &colored, int c){
        // Visit all neighbours of v
        for(int i=0;i<adj[v].size();i++){
            if(colored[adj[v][i]] == c){
                return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<int>> &adj, int V, vector<int> &colored, int m){
        
        for(int v=0;v<V;v++){
            // If vertex v not colored already
            if(colored[v] == -1){
                // Total m color options
                for(int c=0;c<m;c++){
                    // Color only if safe to do so i.e. no adjacent 
                    // neighbour has the same color
                    if(isSafe(adj, v, colored, c)){
                        colored[v] = c;
                        if(helper(adj, V, colored, m)){
                            return true;
                        }
                        colored[v] = -1; // backtrack
                    }
                }
                // Tried all color but didn't find a suitable
                return false;
            }
        }
        // All vertices colored
        return true;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        // Make a adjacency list;
        vector<vector<int>> adj(v);
        vector<int> colored(v, -1);
        for(int i=0;i<edges.size();i++){
            int source = edges[i][0];
            int dest = edges[i][1];
            adj[source].push_back(dest);
            adj[dest].push_back(source); // undirected graph.
        }
        // for(int i=0;i<adj.size();i++){
        //     for(int j=0;j<adj[i].size();j++){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        return helper(adj, v, colored, m);
    }
};
