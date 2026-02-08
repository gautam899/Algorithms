class Solution {
  public:
    void insertSortStack(stack<int> &st, int x){
        if(st.empty() || st.top() <= x){
            st.push(x); return;
        }
        int top = st.top();
        st.pop();
        insertSortStack(st, x);
        st.push(top);
    }
    void sortStack(stack<int> &st) {
        // code here
        // Brute force is to use a vector and then solve
        if(st.empty())return;
        int top = st.top();
        st.pop();
        sortStack(st);
        // Sort the remaining stack.
        insertSortStack(st, top);
    }
};

