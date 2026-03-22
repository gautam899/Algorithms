#include<iostream>
#include<string>
class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        // Better: Using two pointers.
        int n = version1.size(), m = version2.size();
        int i = 0, j = 0;
        int num1 = 0, num2 = 0;
        while (i < n || j < m) {
            if (i < n && version1[i] == '.')
                i++;

            if (j < m && version2[j] == '.')
                j++;

            // Skip the leading zeros
            while (i < n && version1[i] == '0')
                i++;
            while (j < m && version2[j] == '0')
                j++;

            // Form num1 before hitting the end of the string 1 or a '.'
            while (i < n && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            // Form num2 before hitting the end of the string 2 or a '.'
            while (j < m && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            if (num1 > num2)
                return 1;
            if (num1 < num2) {
                // cout<<num1<<" "<<num2;
                return -1;
            }
            // Once we are done comparing numbers just reset the numbers to
            // zero.
            num1 = 0;
            num2 = 0;
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