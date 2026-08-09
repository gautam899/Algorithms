#include <iostream>

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
    bool helper(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL || root2 == NULL)
            return (root1 == root2);
        if (root1->val != root2->val)
            return false;
        return helper(root1->left, root2->right) && helper(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        // Property of mirror tree: The left of a node is the right of the same node in the mirror image.
        return (root == NULL) || helper(root->left, root->right);
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
    bool ans = sol.isSymmetric(node7);
    std::cout << ans << "\n";
    return 0;

    // Every node is visited once and for each node we are doing constant work i.e is comparision of values.
    // Hence time complexity is O(N).
    // Space complexity: Auxiliary space of O(h) which is height of the tree. O(N) for skwed tree and O(LogN) for balanced tree.
}