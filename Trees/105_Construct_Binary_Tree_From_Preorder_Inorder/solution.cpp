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
    TreeNode *helper(std::vector<int> &preorder, int ps, int pe, std::vector<int> &inorder, int is, int ie, std::unordered_map<int, int> &mp)
    {
        // ps -> preorder starting index
        // pe -> preorder ending index
        // is -> inorder starting index
        // ie -> inorder ending index
        if (ps > pe || is > ie)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[ps]);
        int ind_root = mp[preorder[ps]];
        int nums_left = ind_root - is;
        // Now, we would want to form the left subtree of root. For that we need to reduce our look up space.
        // For preorder: ps + 1 -> ps + nums_left, because in preorder traversal we do, root->left->right.
        // For inorder: is, ind_root - 1. Ending at ind_root - 1 because we only wish to process the values that will lie in the left subtree of the root.
        root->left = helper(preorder, ps + 1, ps + nums_left, inorder, is, ind_root - 1, mp);

        // For the right subtree, we can think in the similar manner.
        // For preorder, we skip all the elements that could have been in the left subtree of root i.e. ps + num_left + 1
        // For inorder, we start at ind_root + 1.
        root->right = helper(preorder, ps + nums_left + 1, pe, inorder, ind_root + 1, ie, mp);
        return root;
    }
    TreeNode *formTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        // Using preorder we will decide the root and using inorder we will decide the left and right child.
        // Every time we look for the position of root in the inorder vector, we will have to iterate the inorder vector.
        // But instead of doing that, we create a mapping.
        std::unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        TreeNode *root = helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
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
    std::cout << root->val << " ";
    printInorder(root->right);
}
int main()
{
    std::vector<int> preorder = {3, 9, 20, 15, 7};
    std::vector<int> inorder = {9, 3, 15, 20, 7};
    Solution sol;
    TreeNode *root = sol.formTree(preorder, inorder);
    printInorder(root);
    return 0;
}