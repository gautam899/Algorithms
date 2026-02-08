class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                pq.push(a[i]+b[j]);
                if(pq.size()>k) pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Time complexity O(n*m).
