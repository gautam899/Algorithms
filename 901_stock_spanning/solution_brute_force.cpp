class StockSpanner {
public:
    stack<int> orig;
    StockSpanner() {
        
    }
    
    int next(int price) {
        orig.push(price);
        int count = 0;
        stack<int> dup = orig;
        while(!dup.empty() && dup.top()<=price){
            count++;dup.pop();
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
