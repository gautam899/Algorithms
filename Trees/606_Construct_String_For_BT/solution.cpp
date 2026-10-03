#include <string>

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
    void dfs(TreeNode *root, std::string &ans)
    {
        if (!root)
            return;

        ans += std::to_string(root->val);

        if (root->left != nullptr || root->right != nullptr)
        {
            ans += "(";
            dfs(root->left, ans);
            ans += ")";
        }

        if (root->right != nullptr)
        {
            ans += "(";
            dfs(root->right, ans);
            ans += ")";
        }
    }

    std::string tree2str(TreeNode *root)
    {
        std::string ans = "";
        dfs(root, ans);
        return ans;
    }
};

int main()
{
    /**** TODO: Build a tree and pass it to the function tree2str ****/
    // The time complexity of this implemented approach is O(N) as we are iterating the entire tree.
}