#include <vector>
#include <iostream>
#include <algorithm>

class Trie
{
public:
    struct Node
    {
        std::vector<Node *> link;

        Node() { link = std::vector<Node *>(2, nullptr); }
    };
    Node *root;
    Trie() { root = new Node(); }

    void insert(const int &num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->link[bit])
            {
                node->link[bit] = new Node();
            }
            node = node->link[bit];
        }
    }

    int findMaxXor(const int &num)
    {
        Node *node = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->link[1 - bit])
            {
                ans |= (1 << i);
                node = node->link[1 - bit];
            }
            else
            {
                node = node->link[bit];
            }
        }
        return ans;
    }
};
class Solution
{
public:
    std::vector<int> maximizeXor(std::vector<int> &nums, std::vector<std::vector<int>> &queries)
    {
        Trie *obj = new Trie();
        // Why Sort? Sorting ensures that at iteration all the elements in the trie are less than or equal to mi.
        std::sort(nums.begin(), nums.end());
        std::vector<std::pair<int, std::vector<int>>> temp;
        for (int i = 0; i < queries.size(); i++)
        {
            temp.push_back({i, queries[i]});
        }
        std::sort(temp.begin(), temp.end(), [](const auto &a, const auto &b)
                  { return a.second[1] < b.second[1]; });
        std::vector<int> ans(queries.size(), -1);
        int j = 0;
        for (int i = 0; i < queries.size(); i++)
        {
            while (j < nums.size() && nums[j] <= temp[i].second[1])
            {
                obj->insert(nums[j]);
                j++;
            }
            if (j == 0)
            {
                ans[temp[i].first] = -1;
            }
            else
            {
                ans[temp[i].first] = obj->findMaxXor(temp[i].second[0]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = {0, 1, 2, 3, 4};
    std::vector<std::vector<int>> queries = {{3, 1},
                                             {1, 3},
                                             {5, 6}};
    std::vector<int> ans = sol.maximizeXor(nums, queries);
    return 0;
}