class MyStack {
public:
    // Queue implement first in and first out, but stack operates on last in first out.
    // We need a way to keep the last added element in the queue always in the front. 
    // Intution: We keep two queues q1 and q2. A new element is always added in q2 and then all the elements are added in q2. This will make sure that the last added element stays in the front and hence can be popped first. But now all our elements are in q2. To keeps things simple we just swap q1 with q2 once we rearrange the elements after adding a new.
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
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
