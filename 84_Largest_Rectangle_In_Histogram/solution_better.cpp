class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st;
        vector<int> ls(n, -1);
        vector<int> rs(n, n);
        for (int i = 0; i < n; i++) {

            while (!st.empty() && st.top().first > heights[i]) {
                rs[st.top().second] = i;
                st.pop();
            }
            st.push({heights[i], i});
        }
        // for (auto it : rs) {
        //     cout << it << " ";
        // }
        // cout << endl;
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first > heights[i]) {
                ls[st.top().second] = i;
                st.pop();
            }
            st.push({heights[i], i});
        }
        // for (auto it : ls) {
        //     cout << it << " ";
        // }
        // cout << endl;
        int max_area = 0;
        for(int i=0;i<n;i++){
            int area = (rs[i]-ls[i]-1)*heights[i];
            max_area = max(max_area, area);
        }
        return max_area;
    }
};
