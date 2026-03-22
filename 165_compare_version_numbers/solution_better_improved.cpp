#include<iostream>
#include<string>
class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        // Better: Using two pointers.
        int n = version1.size(), m = version2.size();
        int i = 0, j = 0;
        while (i < n || j < m) {
            // We extract segment by segment.
            int start1 = i;
            while(i<n && version1[i] != '.')i++;
            int end1 = i;

            int start2 = j;
            while(j<m && version2[j] != '.')j++;
            int end2 = j;

            // Skip the zeros
            while(start1<n && version1[start1] == '0')start1++;
            while(start2<m && version2[start2] == '0')start2++;

            int len1 = end1 - start1;
            int len2 = end2 - start2;
            
            // Compare the length of the segments first.
            if(len1 < len2) return -1;
            if(len1 > len2) return 1;

            // Same length segment.
            for(int k=0;k<len1;k++){
                if(version1[start1+k] < version2[start2+k]) return -1;
                if(version1[start1+k] > version2[start2+k]) return 1;
            }
            // Skip the '.'
            i++;
            j++;
        }
        return 0;
    }
};

int main(){
    Solution sol;
    std::string version1 = "1.001";
    std::string version2 = "1";
    int ans = sol.compareVersion(version1, version2);
    std::cout<<ans;
    return 0;

}