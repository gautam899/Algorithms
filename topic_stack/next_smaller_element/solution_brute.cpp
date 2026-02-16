class Solution {
  public:
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            // Hash the first element
            size_t hash1 = hash<T1>{}(p.first);
            // Hash the second element
            size_t hash2 = hash<T2>{}(p.second);
            // Combine the two hash values
            return hash1
                   ^ (hash2 + 0x9e3779b9 + (hash1 << 6)
                      + (hash1 >> 2));
        }
    };
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<pair<int,int>> st;
        unordered_map<pair<int,int>,int,hash_pair> mp;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && st.top().first > arr[i]){
                mp[{st.top().first, st.top().second}] = arr[i];
                st.pop();
            }
            st.push({arr[i], i});
        }
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            auto key = make_pair(arr[i],i);
            auto it = mp.find(key);
            if(it != mp.end()){
                ans.push_back(it->second);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
