#include <iostream>
#include <unordered_map>
#include <vector>

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
    // Instead of keeping 4 variables and involve a lot of mathematics in it, we just keep one index postindex.
    // The important thing is we form the right side of the tree first and then the left side.
    TreeNode *helper(std::vector<int> &postorder, int &postIndex, std::vector<int> &inorder, int inStart, int inEnd, std::unordered_map<int, int> &mp)
    {
        if (inStart > inEnd)
        {
            return nullptr;
        }
        int root_val = postorder[postIndex--];
        TreeNode *root = new TreeNode(root_val);
        int inIndex = mp[root_val];

        // We build the right tree first since postorder goes left->right->root. So
        // if we are moving one index before, that would be the root of the right subtree
        root->right = helper(postorder, postIndex, inorder, inIndex + 1, inEnd, mp);
        root->left = helper(postorder, postIndex, inorder, inStart, inIndex - 1, mp);
        return root;
    }
    TreeNode *formTree(std::vector<int> &postorder, std::vector<int> &inorder)
    {
        std::unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        int postIndex = postorder.size() - 1;
        TreeNode *root = helper(postorder, postIndex, inorder, 0,
                                inorder.size() - 1, mp);
        return root;
    }
};
void printInorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    printInorder(root->left);
    printInorder(root->right);
    std::cout << root->val << " ";
}
int main()
{
    std::vector<int> postorder = {9, 15, 7, 20, 3};
    std::vector<int> inorder = {9, 3, 15, 20, 7};
    Solution sol;
    TreeNode *root = sol.formTree(postorder, inorder);
    printInorder(root);
    return 0;
}