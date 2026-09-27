#include <algorithm>
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
    int findBottomLeftValue(TreeNode *root)
    {
        std::queue<TreeNode *> q;
        TreeNode *leftMost;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            leftMost = q.front();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return leftMost->val;
    }
};

int main()
{
    // TODO: Implement a binary tree.
}