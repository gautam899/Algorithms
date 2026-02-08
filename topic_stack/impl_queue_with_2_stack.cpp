class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        // To keep first added element always at the top of stack. Before we add a new element in s1 we shift all the element from s1 to s2. Push in s1 and then get all the element back from the s2.
        // This way the last added element of the stack will stay at the bottom.
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        if(empty())return -1;
        int temp = s1.top();
        s1.pop();
        return temp;
    }
    
    int peek() {
        return empty() ? -1 : s1.top();
    }
    
    bool empty() {
        return (s1.size() == 0) ? true : false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
