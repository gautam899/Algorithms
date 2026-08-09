#include <vector>
#include <queue>
#include <iostream>

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {};
    TreeNode(int _val, TreeNode *_left, TreeNode *_right) : val(_val), left(_left), right(_right) {};
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int left_d = maxDepth(root->left);
        int right_d = maxDepth(root->right);

        return 1 + std::max(left_d, right_d);
    }
};

int main()
{
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(2, node1, node2);
    TreeNode *node6 = new TreeNode(2, node3, node4);
    TreeNode *node7 = new TreeNode(1, node5, node6);
    Solution sol;
    int ans = sol.maxDepth(node1);
    std::cout << ans << "\n";
    return 0;
}