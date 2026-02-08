class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<(int)s.length();i++){
            // Only push if it's a opening parenthesis.
            char c = s[i];
            if(c == '(' || c == '[' || c == '{'){
                st.push(s[i]);
            }                
            else {
                // If it's a closing paren and the stack is empty, it's unmatched
                if(st.empty()){
                    return false;
                }
                if((c == ')' && st.top() != '(') || (c == ']' && st.top() != '[') || (c == '}' && st.top() != '{')){
                    return false;
                }
                st.pop(); // Pop if matched.
            }
        }
        
        return st.empty();
    }
};
