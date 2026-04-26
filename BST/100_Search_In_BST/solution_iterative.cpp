#include <iostream>

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
    TreeNode *_search(TreeNode *root, int val)
    {
        while (root && root->val != val)
        {
            if (val < root->val)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return root;
    }
};
int main()
{
    // TODO: Create a Tree
    return 0;
}