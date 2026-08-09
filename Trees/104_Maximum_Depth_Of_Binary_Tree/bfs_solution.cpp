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

        std::queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty())
        {
            depth++;
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *node = q.front();
                q.pop();
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
    int ans = sol.maxDepth(node1);
    std::cout << ans << "\n";
    return 0;
}