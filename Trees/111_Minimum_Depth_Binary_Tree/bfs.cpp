#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

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
    int minDepth(TreeNode *root)
    {
        // Reach the nearest leaf node as early as possible. BFS is optimal in that case.
        if (!root)
            return 0;
        std::queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty())
        {
            depth++;
            int lsize = q.size();
            for (int i = 0; i < lsize; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (!node->left && !node->right)
                {
                    return depth;
                }
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return depth;
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
    int ans = sol.minDepth(node1);
    std::cout << ans << "\n";
    return 0;
    // Time Complecity: O(N) in the worst case
    // Space Complexity: O(N) in the worst case (skewed tree)
}