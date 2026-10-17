#include <string>
#include <vector>
#include <unordered_map>

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
    std::string dfs(TreeNode *root, std::vector<TreeNode *> &ans,
                    std::unordered_map<std::string, int> &mp)
    {
        if (!root)
            return "#";

        std::string s = std::to_string(root->val);
        s = s + "," + dfs(root->left, ans, mp);
        s = s + "," + dfs(root->right, ans, mp);
        mp[s]++;
        if (mp[s] == 2)
        {
            ans.push_back(root);
        }
        return s;
    }
    std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        // If we include the null pointer as # or null in the serialized string,
        // then a preorder traversal can uniquely identify a tree.
        std::vector<TreeNode *> ans;
        std::unordered_map<std::string, int> mp;
        dfs(root, ans, mp);
        return ans;
    }
};