#include <iostream>
#include <vector>

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
    TreeNode(int val, TreeNode *left, TreeNode *right)
        : val(val), left(left), right(right) {};
};

class Codec
{
public:
    void findLeftBoundary(TreeNode *root, std::vector<int> &ans)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return;

        ans.push_back(root->val);

        if (root->left != nullptr)
            findLeftBoundary(root->left, ans);
        else
            findLeftBoundary(root->right, ans);
    }

    void findLeafBoundary(TreeNode *root, std::vector<int> &ans)
    {
        if (!root)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(root->val);
        }
        else
        {
            findLeafBoundary(root->left, ans);
            findLeafBoundary(root->right, ans);
        }
    }

    void findRightBoundary(TreeNode *root, std::vector<int> &ans)
    {
        // If a null TreeNode or leaf TreeNode.
        if (!root || (root->left == nullptr && root->right == nullptr))
            return;

        if (root->right != nullptr)
            findRightBoundary(root->right, ans);
        else
            findRightBoundary(root->left, ans);
        ans.push_back(root->val);
    }

    std::vector<int> boundaryTraversal(TreeNode *root)
    {
        // code here
        std::vector<int> ans = {root->val};

        if (root->left == nullptr && root->right == nullptr)
            return ans;
        findLeftBoundary(root->left, ans);
        findLeafBoundary(root, ans);
        findRightBoundary(root->right, ans);
        return ans;
    }
};