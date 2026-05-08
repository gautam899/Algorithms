#include <iostream>
#include <vector>
#include <climits>   // For variables like INT_MIN, INT_MAX
#include <algorithm> // std::max, std::min

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
    // The intution is do something similar to what we do in validating a BST i.e. carrying a range of
    // values for the root->val to lie in, for it to be a BST. In this case, we would want to have is a Data structure
    // storing the <min, max, num_nodes> for each node. While traversing, we would want to evaluate this for every node and return
    // to it's parent. If we have a left<min, max, num_nodes> and right<min, max, num_nodes> for a node, this would means in what range the left
    // and right subtree of this node lie in. Using these ranges, we check for root that if the subtree rooted at this tree is a BST.
    std::vector<int> traverse(TreeNode *root, int &ans)
    {
        if (!root)
        {
            return {INT_MAX, INT_MIN, 0}; // This is to ensure incase it is a leaf node or node with one child, this should satisfy the condition for BST. Because root->val will not be less than left[1] i.e. INT_MIN, and not greater that right[0] i.e. INT_MAX.
        }
        std::vector<int> left(traverse(root->left, ans)), right(traverse(root->right, ans));

        // Check for a BST. When are we not going to have a BST. If the root value is less the max possible value of the left subtree,
        // or if the root value is greater than the minimum possible value in the right subtree. If either of these conditions are true, we
        // will say that the tree rooted at root is not a BST
        if (left.empty() || right.empty() || root->val <= left[1] || root->val >= right[0])
            return {};

        int num_node = 1 + left[2] + right[2];
        ans = std::max(ans, num_node);
        // Update the range.
        return {std::min(root->val, left[0]), std::max(root->val, right[1]), num_node};
    }

    int __largestBSTsubtree(TreeNode *root)
    {
        int ans = 0;
        traverse(root, ans);
        return ans; // We do not want to return -ve sum.
    }
};

int main()
{
    Solution sol;
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(4, node1, node2);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(6);
    TreeNode *node6 = new TreeNode(5, node4, node5);
    TreeNode *node7 = new TreeNode(2);
    TreeNode *node8 = new TreeNode(3, node7, node6);
    TreeNode *node9 = new TreeNode(1, node3, node8);
    TreeNode *root = node9;
    int ans = sol.__largestBSTsubtree(root);
    std::cout << ans << "\n";
    return 0;
}