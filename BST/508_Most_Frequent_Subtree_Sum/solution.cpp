#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min
#include <unordered_map>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {};
};

class Solution
{
public:
    int helper(TreeNode *root, std::unordered_map<int, int> &mp, int &max_freq)
    {
        if (!root)
            return 0;
        int left = helper(root->left, mp, max_freq);
        int right = helper(root->right, mp, max_freq);

        int curr_sum = root->val + left + right;
        mp[curr_sum]++;
        max_freq = std::max(max_freq, mp[curr_sum]);
        return curr_sum;
    }
    std::vector<int> findFrequentTreeSum(TreeNode *root)
    {
        std::unordered_map<int, int> mp; // Sum -> Freq
        int max_freq = 0;
        helper(root, mp, max_freq);
        std::vector<int> ans;
        std::cout << max_freq << "\n";
        // Gather all sum with freq equal to max_freq
        for (auto it : mp)
        {
            if (it.second == max_freq)
                ans.push_back(it.first);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(4, node1, node2);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(6);
    TreeNode *node6 = new TreeNode(5, node4, node5);
    TreeNode *node7 = new TreeNode(2);
    TreeNode *node8 = new TreeNode(3, node7, node6);
    TreeNode *node9 = new TreeNode(1, node3, node8);
    TreeNode *root = node9;
    std::vector<int> ans = sol.findFrequentTreeSum(root);
    for (auto it : ans)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";
    return 0;
}