class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string start = strs[0], end = strs[n - 1];
        int mini = min(start.size(), end.size());
        int i = 0;
        while (i < mini && start[i] == end[i]) {
            i++;
        }
        return start.substr(0, i);
        // The intution behind the above approach is how sorting works. Once we sort the array we just have to compare the first and last strings of the given vector.
    }
};
