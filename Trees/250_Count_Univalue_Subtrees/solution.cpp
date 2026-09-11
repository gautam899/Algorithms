#include <iostream>

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
    bool helper(TreeNode *root, int &ans)
    {
        if (!root) // Empty tree is a univalue tree.
            return true;

        bool left = helper(root->left, ans);
        bool right = helper(root->right, ans);

        // If either of left or right is false, the current subtree is not a univalue tree, return false
        if (!left || !right)
            return false;

        /*
            Time to compare the root's left and right value with itself.
            The catch is, if the root's left or right is null, we mark the leftVal or rightVal is the root->val
            We do this for comparision.
        */

        int leftVal = root->left ? root->left->val : root->val;
        int rightVal = root->right ? root->right->val : root->val;

        if (leftVal == rightVal && root->val == rightVal)
        {
            ans++;
            return true;
        }
        return false;
    }
    int countUnivalueTrees(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};

int main()
{
    return 0;
}
/*
    The T.C of the code is O(N) as every node is traversed once.
    The auxiliary stack space complexity is O(N).
*/