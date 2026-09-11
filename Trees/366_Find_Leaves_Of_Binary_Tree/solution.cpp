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

/*
    The intuition here in this problem is that we do not actually have to remove the nodes to find the ans, but rather
    simulate removal of nodes using post-order dfs. The catch is to keep in mind that the nodes with same height from bottom of the
    tree will become leaf node at the same time.
*/
class Solution
{
public:
    int dfs(TreeNode *root, std::vector<std::vector<int>> &ans)
    {
        if (!root)
            return 0; // NULL nodes have height zero.

        int leftH = dfs(root->left, ans);
        int rightH = dfs(root->right, ans);

        int currHeight = std::max(leftH, rightH);

        if (ans.size() == currHeight)
        {
            ans.push_back({});
        }
        ans[currHeight].push_back(root->val);

        return 1 + currHeight;
    }
    std::vector<std::vector<int>> findLeaves(TreeNode *root)
    {
        std::vector<std::vector<int>> ans;
        dfs(root, ans);
        return ans;
    }
    /*
        The time complexity is O(N) and space complexity is O(1) if we ignore the auxiliary stack space of O(N)
    */
};