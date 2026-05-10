#include <iostream>
#include <vector>
#include <queue>

class MedianFinder
{
public:
    // To find the median in a stream of integers, we need to divide the stream of integers into two halves.
    // The left and right, both must contain integers in sorted order. The left must contain the integers sorted in ascending order
    // and the right must contain intergers sorted in descending order. We must make sure that the values in the left half are always smaller
    // than the values in the right halves.
    // What kind of data structure can we use to ensure this??
    // Priority queue!, we use a max heap for the left half and a min heap for the right half. Why?
    // Because when we find the median, we would want to easily access the middle element of the integer array out of the stream.
    // If the array is even length then we would want to, take the max of the left half and min of the right half optimally. Having a max Heap
    // For the left will give the max of the left Half and having a min Heap for the right half will give us the minimum or left most of the right half
    // To ensure the above, we need to make sure of a few things
    // 1. The size difference of the two heaps must not exceed 1
    // 2. Every element in the left side Heap i.e. maxHeap should be less than the right side heap i.e. min Heap.

    std::priority_queue<int, std::vector<int>, std::greater<int>> right_half_minH; // Min Heap
    std::priority_queue<int> left_half_maxH;                                       // Max heap
    MedianFinder() {}

    void addNum(int num)
    {
        // We push the number first in the maxH and then we rearrange.
        // 1.
        left_half_maxH.push(num);
        // 2. The maxH might have a larger number than the right_half minH. We push the top of the maxH into the minH.
        right_half_minH.push(left_half_maxH.top());
        left_half_maxH.pop();
        if (right_half_minH.size() > left_half_maxH.size())
        {
            // push the top of the minH into the max Heap
            left_half_maxH.push(right_half_minH.top());
            right_half_minH.pop();
        }
        /*** The above steps will be making sure that the size difference between the left and the right half will be atmost 1 all the times and left_half always have smaller elements then the right half ***/
    }

    double findMedian()
    {
        // Either the sizes will be equal(even element) or left half will be one more than the right half(odd elements)
        if (left_half_maxH.size() > right_half_minH.size())
        {
            return left_half_maxH.top();
        }
        else
        {
            return (double)(left_half_maxH.top() + right_half_minH.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    MedianFinder sol;
    return 0;
}
