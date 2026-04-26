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

// The intution behind this improved approach is to use a global index preIndex instead of using start and ending indices
// for the preorder vector. We pass this by index by reference and keep track of the index of the root val in the inorder
// vector as that will give us the range for left and right children of the root.
class Solution
{
public:
    TreeNode *helper(std::vector<int> &preorder, int &preIndex, std::vector<int> &inorder, int inStart, int inEnd, std::unordered_map<int, int> &mp)
    {
        if (inStart > inEnd)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preIndex++]);
        int indRoot = mp[root->val];

        root->left = helper(preorder, preIndex, inorder, inStart, indRoot - 1, mp);
        root->right = helper(preorder, preIndex, inorder, indRoot + 1, inEnd, mp);
        return root;
    }
    TreeNode *formTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        std::unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        int preIndex = 0;
        TreeNode *root = helper(preorder, preIndex, inorder, 0, inorder.size() - 1, mp);
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