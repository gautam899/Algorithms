#include<iostream>
#include<stack> // stack
#include<algorithm> // min()
#include<climits> // INT_MIN, INT_MAX
#include<utility> // Pair

class MinStack {
public:
    std::stack<std::pair<int,int>> st;
    int mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        // If we are pushing the first element.
        if(st.empty()){
            st.push({val,val});
            mini = val;
            return;
        }
        mini = std::min(val,st.top().second); 
        st.push({val, mini});
    }
    
    void pop() {
        // When popping: Update the minimum by now. The new minimum will be the one after popping but only if the the stack is not empty.
        st.pop();
        if(!st.empty()) mini = st.top().second;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return mini;
    }
};

int main() {
   MinStack* obj = new MinStack();
   obj->push(21);
   obj->push(19);
   obj->push(22);
   obj->pop();
   int param_3 = obj->top();
   int param_4 = obj->getMin();
   std::cout<<param_3<<endl;
   std::cout<<param_4<<endl;
   return 0;
}
