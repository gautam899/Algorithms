#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // In order to maximize the content(happy) children is to give the cookies first to children whose greed factor is least and we will start with the smallest cookie.
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n_kids = g.size(), n_cookies = s.size();
        vector<int> visited(n_kids,0);
        int count=0;
        // For each cookie size check for the kids.
        // Note: If a cookie does not content a specific kid that means no cookie greater than current will content that kid.
        for(int i=0;i<n_cookies;i++){
            for(int j=0;j<n_kids;j++){
                if(visited[j] == 1){
                    continue; // the kid already have the cookie.
                }
                if(s[i]>=g[j] && visited[j] == 0){
                    count++;
                    visited[j] = 1;
                    break; // a cookie can be only given once.
                }
                else if(s[i]<g[j]){
                    break; // Move to the next cookie as the next is kid is only going to have greater greed.
                }
            }
        }
        return count;

    }
};

int main(){
	vector<int> g = {1,2,3};
	vector<int> s = {3};
	Solution sol;
	int ans = sol.findContentChildren(g,s);
	cout<<ans;
	return ans;
}
