#include <iostream>
#include <vector>

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
    void helper(TreeNode *root, double val, double diff, int &ans)
    {
        if (!root)
            return;
        double x = abs(root->val - val);
        if (x < diff || (x < diff && root->val < ans))
        {
            diff = x;
            ans = root->val;
        }

        if (val < root->val)
            helper(root->left, val, diff, ans);
        else
            helper(root->left, val, diff, ans);
    }
    int closestNode(TreeNode *root, double val)
    {
        // I need two variables. The current minimum difference till now, and ans.
        double diff = 1e9;
        int ans = 0;
        helper(root, val, diff, ans);
        return ans;
    }
};

int main()
{
    Solution sol;
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    int val = sol.closestNode(node1, 3.5);
    std::cout << val << std::endl;
}