#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode *root)
    {
        std::vector<std::vector<int>> ans;
        std::vector<int> level;
        if (!root)
            return ans;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            level.resize(0);
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(level);
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
