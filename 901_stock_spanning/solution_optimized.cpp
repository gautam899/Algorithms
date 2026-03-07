class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    // Instead of creating a duplicate and count the number of elements before the next greater element, we only keep one stack. A question that we can ask ourself is, do we really to keep the elements smaller than the current element in the stack? No. Going ahead if there is a number smaller that curr, the elements smaller than the curr will be of no use. Or else if there is greater element than the curr, the span of the current element will store the span of all the smaller than curr element.
    int next(int price) {
        int count = 1;
        while(!st.empty() && st.top().first <= price){
            count += st.top().second;
            st.pop();
        }
        st.push({price, count});
        return count;

        // Time complexity: Worst case O(N). If it's a decreasing stream.
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
