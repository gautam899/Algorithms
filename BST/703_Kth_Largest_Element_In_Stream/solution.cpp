#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <functional> // greater

class Code
{
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int K;
    void KthLargest(int k, std::vector<int> &nums)
    {
        K = k;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            if (pq.size() > K)
            {
                pq.pop();
            }
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > K)
        {
            pq.pop();
        }
        return pq.top();
    }
};

int main()
{
    Code codec;
    int k = 3;
    std::vector<int> v = {4, 5, 8, 3};
    codec.KthLargest(k, v);
    std::cout << codec.add(2) << std::endl;
    std::cout << codec.add(5) << std::endl;
    std::cout << codec.add(10) << std::endl;
    std::cout << codec.add(9) << std::endl;
    std::cout << codec.add(4) << std::endl;
    return 0;
    // Time Complexity: The complexity with using priority queue is O(LogN).
}