class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int max_area = 0;
        // To avoid the second while loop we instead iterate from 0 to n  and not 0->n-1.
        // This will handle the case for all the elements which do not have right smaller element.
        for(int i=0;i<=n;i++){
            int curr_height = i == n ? 0 : heights[i];
            while(!st.empty() && curr_height < heights[st.top()]){
                int barH = heights[st.top()];
                st.pop();
                int right_smaller = i;
                int left_smaller = st.empty() ? -1 : st.top();
                int width = right_smaller - left_smaller - 1;
                max_area = max(max_area, width*barH);
            }
            st.push(i);
        }
        return max_area;
    }
};
