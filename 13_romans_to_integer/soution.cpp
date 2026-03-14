class Solution {
public:
    /* The intution if to parse the string two character's at a time. If the first character is 
     * larger than the second, we simply add it to the res. If the first character is less than the second character
     * This is the special case for 4,9,40,90,400,900. 4 is 5-1, 4->IV, 9->IX, 40->XL, 90->XC, 400->CD, 900->CM. 
     * If we notice the first roman is less than the second in these case. 
     */
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        // We iterate two character at a time and decide as per the intution discussed above.
        int i=0;
        int res = 0;
        while(i<s.size()){
            char a = s[i];
            char b = ' ';
            if(i+1 < s.size()){
                b = s[i+1];
            }
            if( b!= ' '&& mp[a] >= mp[b]){
                res += mp[a];
            } else if(b!= ' '&& mp[a] < mp[b]){
                res -= mp[a]; // These are the cases of 4,9,40,40,400,900.
			      // If the Roman is XIV res is 10 after traversing X. But then we see I<V, So we subtract I from res and in the next iteration we are going to add V.
            } else {
                res += mp[a];
            }
            i++;
        }
        return res;
    }
};
