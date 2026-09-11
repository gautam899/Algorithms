#include <iostream>
#include <vector>
#include <stack>
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
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        if (!root)
            return nullptr;
        TreeNode *ans = nullptr;
        while (!root)
        {
            if (root->val > p->val)
            {
                // Could be our successor but we might find a smaller inorder successor on the left
                ans = root;
                root = root->left;
            }
            else
            {
                // If the root->val is less than p->val, inorder successor will lie in the right side.
                root = root->right;
            }
        }
        return ans;
    }
};

int main()
{
}