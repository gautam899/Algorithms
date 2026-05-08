#include <iostream>
#include <climits> // or limits.h
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    // Constructor for root node.
    TreeNode(int val = 0, TreeNode *parent = nullptr) : val(val), left(nullptr), right(nullptr), parent(parent) {};
    // For non-leaf node.
    TreeNode(int val, TreeNode *left, TreeNode *right, TreeNode *parent) : val(val), left(left), right(right), parent(parent) {};
};

class Operations
{
public:
    // This function get's called only when a tree rooted at root is BST.
    bool _validate_BST(TreeNode *root, long minimum, long maximum)
    {
        if (!root)
            return true;
        if (!(root->val > minimum && root->val < maximum))
            return false;

        return _validate_BST(root->left, minimum, root->val) &&
               _validate_BST(root->right, root->val, maximum);
    }
    int find_ans(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = find_ans(root->left);
        int right = find_ans(root->right);
        return (root->val + left + right);
    }
    int ans = INT_MIN;
    int helper(TreeNode *root)
    {
        if (!root)
            return 0;
        if (_validate_BST(root, LONG_MIN, LONG_MAX))
        {
            ans = std::max(ans, find_ans(root));
        }
        int l = helper(root->left);
        int r = helper(root->right);
        return 0;
    }

    int maxSumBST(TreeNode *root)
    {
        helper(root);
        return (ans < 0) ? 0 : ans;
    }
};

int main()
{
    Operations op;

    TreeNode *node1 = new TreeNode(8, nullptr);
    TreeNode *node2 = new TreeNode(3, nullptr, nullptr, node1);
    TreeNode *node3 = new TreeNode(10, nullptr, nullptr, node1);
    TreeNode *node4 = new TreeNode(1, nullptr, nullptr, node2);
    TreeNode *node5 = new TreeNode(6, nullptr, nullptr, node2);
    TreeNode *node6 = new TreeNode(14, nullptr, nullptr, node3);
    TreeNode *node7 = new TreeNode(4, nullptr, nullptr, node5);
    TreeNode *node8 = new TreeNode(7, nullptr, nullptr, node5);
    TreeNode *node9 = new TreeNode(13, nullptr, nullptr, node6);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node5->left = node7;
    node5->right = node8;
    node3->right = node6;
    node6->left = node9;
    TreeNode *root = node1;
    int ans = op.maxSumBST(root);
    std::cout << ans << "\n";

    // The above code is logically fine but the time complexity is O(N^2) worst case.
    // If we consider a right skewed tree, 1->2->3->4->5->6->7->8.
    // For every node, we validate and then we find the sum.
    // This will be like N + (N+1) + (N+2) + (N+2)..
    // N(N+1)/2 ~ O(N^2).
    return 0;
}