class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // Another better approach will be to use a stack.
        // We discard the elements which are not celeb and only keep 
        // the one that are actually celeb.
        // At last, we check, whether the one in the stack is actually a
        // celeb.
        
        stack<int> st;
        int n = mat.size();
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(mat[a][b] == 1){
                st.push(b); // a knows b, a cannot be a celeb
            } else{
                st.push(a);
            }
        }
        
        // Possible celeb
        int celeb = st.top(); st.pop();
        // cout<<celeb<<endl;
        for(int i=0;i<n;i++){
            // If i != celeb and celeb knows i or i doesn't know celeb.
            if(celeb != i && (mat[celeb][i] == 1 || mat[i][celeb] == 0)){
                return -1;
            }
        }
        return celeb;
        
        
    }
};
