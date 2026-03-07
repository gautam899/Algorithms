class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        // Reverse the string
        reverse(s.begin(), s.end());
        int l=0;
        int starting = 0,k=0;
        while(l<n){
            while(l<n && s[l] == ' ')l++; // Ignore the spaces;
            
            // If r < n(i.e) still have more words left and it is not the beginning of the string. Set the current position of k as space
            if(l < n && k > 0) s[k++] = ' ';
            
            starting = k; // Point the starting to k. We will need this to reverse the word.
            while( l<n && s[l] != ' ') s[k++] = s[l++];

            // Reverse the current word. Starting from l till r-1
            reverse(s.begin() + starting, s.begin()+k);
        }
        s.resize(k);
        return s;
    }
};
