#include <iostream>
#include <vector>
#include <queue>

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode()
    {
        val = 0;
    }

    TreeNode(int _val)
    {
        val = _val;
    }

    TreeNode(int _val, TreeNode *_left, TreeNode *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution
{
public:
    std::vector<int> rightSideView(TreeNode *root)
    {
        // Perform a level order traversal
        std::vector<int> ans;
        std::queue<TreeNode *> q;
        if (!root)
            return ans;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            ans.push_back(q.front()->val); // Right most node of the level.
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->right)
                    q.push(node->right);
                if (node->left)
                    q.push(node->left);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    return 0;
}