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
    TreeNode *ans = nullptr;
    double max_average = 0.0;
    std::vector<int> traverse(TreeNode *root)
    {
        if (!root)
        {
            return {0, 0}; // {num_node, curr_sum}
        }
        std::vector<int> left(traverse(root->left)), right(traverse(root->right));
        int curr_sum = root->val + left[2] + right[2];
        int num_node = 1 + left[0] + right[0];
        double av = curr_sum / num_node;
        // If the found average is greater than max_average found till now.
        if (av > max_average)
        {
            max_average = av;
            ans = root;
        }
        return {num_node, curr_sum};
    }

    void __maxAverageSubtree(TreeNode *root)
    {
        traverse(root);
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
    sol.__maxAverageSubtree(root);
    std::cout << sol.ans->val << "\n";
    return 0;
}