#include<iostream>
#include<vector>
#include<queue>

class MedianFinder {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> right_half_minH; // Min Heap
    std::priority_queue<int>  left_half_maxH; // Max heap
    MedianFinder() {}
    
    void addNum(int num) {
        // We push the number first in the maxH and then we rearrange.
        // 1.
        left_half_maxH.push(num);
        // 2. The maxH might have a larger number than the right_half minH. We push the top of the maxH into the minH.
        right_half_minH.push(left_half_maxH.top());
        left_half_maxH.pop(); 
        if(right_half_minH.size() > left_half_maxH.size()){
            // push the top of the minH into the max Heap
            left_half_maxH.push(right_half_minH.top());
            right_half_minH.pop();
        }
        /*** The above steps will be making sure that the size difference between the left and the right half will be atmost 1 all the times and left_half always have smaller elements then the right half ***/
    }
    
    double findMedian() {
        // Either the sizes will be equal(even element) or left half will be one more than the right half(odd elements)
        if(left_half_maxH.size() > right_half_minH.size()){
            return left_half_maxH.top();
        } else {
            return (double)(left_half_maxH.top() + right_half_minH.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    Solution sol;

    MedianFinder* obj = new MedianFinder();
    obj->addNum(num);
    double param_2 = obj->findMedian();

}
