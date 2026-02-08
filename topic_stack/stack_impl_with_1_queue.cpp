class MyStack {
public:
    queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
       q1.push(x);
       int size = q1.size();
       for(int i=1;i<size;i++){
          // Pop from the front and push are the back
          q1.push(q1.front());
          q1.pop();
       }
    }
    
    int pop() {
        if(empty())return -1;
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
        if(empty()) return -1;
        return q1.front();
    }
    
    bool empty() {
        if(q1.size() == 0)return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
