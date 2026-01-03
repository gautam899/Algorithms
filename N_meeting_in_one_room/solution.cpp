#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        if(n == 1)return 1;
        
        vector<pair<int,int>> meetings;
        for(int i=0;i<n;i++){
            meetings.push_back({end[i], start[i]}); // keep the key first
        }
        sort(meetings.begin(),meetings.end());
        // First meeting will always take place.
        int next_start = meetings[0].first; // ending time of the current meeting
        // will be a limit for the second meeting to start.
        int count = 1;
        for(int i=1;i<n;i++){
            if(meetings[i].second > next_start){
                count++;
                next_start = meetings[i].first;
            }
        }
        return count;
    }
};

int main() {
	vector<int> start = {1,3,0,5,8,5};
	vector<int> end = {2,4,6,7,9,9};
	Solution sol;
	int ans = sol.maxMeetings(start, end);
	cout<<ans<<"\n";
	return 0;
}
